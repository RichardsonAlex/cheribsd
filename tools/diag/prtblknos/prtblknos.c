/*
 * Copyright (c) 1998, 2003, 2013, 2018 Marshall Kirk McKusick.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHALL KIRK MCKUSICK ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL MARSHALL KIRK MCKUSICK BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/param.h>
#include <ufs/ffs/fs.h>

#include <err.h>
#include <stdio.h>
#include <libufs.h>

union dinode {
	struct ufs1_dinode dp1;
	struct ufs2_dinode dp2;
};

void prtblknos(struct uufsd *disk, union dinode *dp);

static void  indirprt(struct uufsd *, int, int, int, ufs2_daddr_t, int);
static char *distance(struct fs *, daddr_t, daddr_t);
static void  printblk(struct fs *, int, ufs2_daddr_t, int, int);

void
prtblknos(disk, dp)
	struct uufsd *disk;
	union dinode *dp;
{
	int i, len, lbn, mode, frags, numblks, blksperindir;
	ufs2_daddr_t blkno;
	struct fs *fs;
	off_t size;

	fs = (struct fs *)&disk->d_sb;
	if (fs->fs_magic == FS_UFS1_MAGIC) {
		size = dp->dp1.di_size;
		mode = dp->dp1.di_mode;
	} else {
		size = dp->dp2.di_size;
		mode = dp->dp2.di_mode;
	}
	switch (mode & IFMT) {
	case IFIFO:
		printf("fifo\n");
		return;
	case IFCHR:
		printf("character device\n");
		return;
	case IFBLK:
		printf("block device\n");
		return;
	case IFSOCK:
		printf("socket\n");
		return;
	case IFWHT:
		printf("whiteout\n");
		return;
	case IFLNK:
		if (size == 0) {
			printf("empty symbolic link\n");
			return;
		}
		if (size < fs->fs_maxsymlinklen) {
			printf("symbolic link referencing %s\n",
			    (fs->fs_magic == FS_UFS1_MAGIC) ?
			    (char *)dp->dp1.di_db :
			    (char *)dp->dp2.di_db);
			return;
		}
		printf("symbolic link\n");
		break;
	case IFREG:
		if (size == 0) {
			printf("empty file\n");
			return;
		}
		printf("regular file, size %ld\n", size);
		break;
	case IFDIR:
		if (size == 0) {
			printf("empty directory\n");
			return;
		}
		printf("directory, size %ld\n", size);
		break;
	}
	numblks = howmany(size, fs->fs_bsize);
	len = numblks < UFS_NDADDR ? numblks : UFS_NDADDR;
	for (i = 0; i < len; i++) {
		if (i < numblks - 1)
			frags = fs->fs_frag;
		else
			frags = howmany(size % fs->fs_bsize,
					  fs->fs_fsize);
		if (fs->fs_magic == FS_UFS1_MAGIC)
			blkno = dp->dp1.di_db[i];
		else
			blkno = dp->dp2.di_db[i];
		printblk(fs, i, blkno, frags, numblks);
	}

	blksperindir = 1;
	len = numblks - UFS_NDADDR;
	lbn = UFS_NDADDR;
	for (i = 0; len > 0 && i < UFS_NIADDR; i++) {
		if (fs->fs_magic == FS_UFS1_MAGIC)
			blkno = dp->dp1.di_ib[i];
		else
			blkno = dp->dp2.di_ib[i];
		indirprt(disk, i, blksperindir, lbn, blkno, numblks);
		blksperindir *= NINDIR(fs);
		lbn += blksperindir;
		len -= blksperindir;
	}

	/* dummy print to flush out last extent */
	printblk(fs, numblks, 0, frags, 0);
}

static void
indirprt(disk, level, blksperindir, lbn, blkno, lastlbn)
	struct uufsd *disk;
	int level;
	int blksperindir;
	int lbn;
	ufs2_daddr_t blkno;
	int lastlbn;
{
	char indir[MAXBSIZE];
	struct fs *fs;
	int i, last;

	fs = (struct fs *)&disk->d_sb;
	if (blkno == 0) {
		printblk(fs, lbn, blkno,
		    blksperindir * NINDIR(fs) * fs->fs_frag, lastlbn);
		return;
	}
	printblk(fs, lbn, blkno, fs->fs_frag, -level);
	/* read in the indirect block. */
	if (bread(disk, fsbtodb(fs, blkno), indir, fs->fs_bsize) == -1) {
		warn("Read of indirect block %jd failed", (intmax_t)blkno);
		/* List the unreadable part as a hole */
		printblk(fs, lbn, 0,
		    blksperindir * NINDIR(fs) * fs->fs_frag, lastlbn);
		return;
	}
	last = howmany(lastlbn - lbn, blksperindir) < NINDIR(fs) ?
	    howmany(lastlbn - lbn, blksperindir) : NINDIR(fs);
	if (blksperindir == 1) {
		for (i = 0; i < last; i++) {
			if (fs->fs_magic == FS_UFS1_MAGIC)
				blkno = ((ufs1_daddr_t *)indir)[i];
			else
				blkno = ((ufs2_daddr_t *)indir)[i];
			printblk(fs, lbn + i, blkno, fs->fs_frag, lastlbn);
		}
		return;
	}
	for (i = 0; i < last; i++) {
		if (fs->fs_magic == FS_UFS1_MAGIC)
			blkno = ((ufs1_daddr_t *)indir)[i];
		else
			blkno = ((ufs2_daddr_t *)indir)[i];
		indirprt(disk, level - 1, blksperindir / NINDIR(fs),
		    lbn + blksperindir * i, blkno, lastlbn);
	}
}

static char *
distance(fs, lastblk, firstblk)
	struct fs *fs;
	daddr_t lastblk;
	daddr_t firstblk;
{
	daddr_t delta;
	int firstcg, lastcg;
	static char buf[100];

	if (lastblk == 0)
		return ("");
	delta = firstblk - lastblk - 1;
	firstcg = dtog(fs, firstblk);
	lastcg = dtog(fs, lastblk);
	if (firstcg == lastcg) {
		snprintf(buf, 100, " distance %jd", (intmax_t)delta);
		return (&buf[0]);
	}
	snprintf(buf, 100, " cg %d blk %jd to cg %d blk %jd",
	    lastcg, (intmax_t)dtogd(fs, lastblk), firstcg,
	    (intmax_t)dtogd(fs, firstblk));
	return (&buf[0]);
}
	

static char *indirname[UFS_NIADDR] = { "First", "Second", "Third" };

static void
printblk(fs, lbn, blkno, numblks, lastlbn)
	struct fs *fs;
	int lbn;
	ufs2_daddr_t blkno;
	int numblks;
	int lastlbn;
{
	static int seq;
	static daddr_t lastindirblk, lastblk, firstblk;

	if (lastlbn <= 0)
		goto flush;
	if (seq == 0) {
		seq = howmany(numblks, fs->fs_frag);
		firstblk = blkno;
		return;
	}
	if (lbn == 0) {
		seq = howmany(numblks, fs->fs_frag);
		lastblk = 0;
		firstblk = blkno;
		lastindirblk = 0;
		return;
	}
	if (lbn < lastlbn && ((firstblk == 0 && blkno == 0) ||
	    (firstblk == BLK_NOCOPY && blkno == BLK_NOCOPY) ||
	    (firstblk == BLK_SNAP && blkno == BLK_SNAP) ||
	    blkno == firstblk + seq * fs->fs_frag)) {
		seq += howmany(numblks, fs->fs_frag);
		return;
	}
flush:
	if (seq == 0)
		goto prtindir;
	if (firstblk <= BLK_SNAP) {
		if (seq == 1)
			printf("\tlbn %d %s\n", lbn - seq,
			    firstblk == 0 ? "hole" :
			    firstblk == BLK_NOCOPY ? "nocopy" :
			    "snapblk");
		else
			printf("\tlbn %d-%d %s\n",
			    lbn - seq, lbn - 1,
			    firstblk == 0 ? "hole" :
			    firstblk == BLK_NOCOPY ? "nocopy" :
			    "snapblk");
	} else if (seq == 1) {
		if (numblks == 1)
			printf("\tlbn %d blkno %jd%s\n", lbn - seq,
			   (intmax_t)firstblk, distance(fs, lastblk, firstblk));
		else
			printf("\tlbn %d blkno %jd-%jd%s\n", lbn - seq,
			    (intmax_t)firstblk,
			    (intmax_t)(firstblk + numblks - 1),
			    distance(fs, lastblk, firstblk));
		lastblk = firstblk + numblks - 1;
	} else {
		printf("\tlbn %d-%d blkno %jd-%jd%s\n", lbn - seq, lbn - 1,
		    (intmax_t)firstblk, (intmax_t)(firstblk +
		    (seq - 1) * fs->fs_frag + numblks - 1),
		    distance(fs, lastblk, firstblk));
		lastblk = firstblk + (seq - 1) * fs->fs_frag + numblks - 1;
	}
	if (lastlbn > 0 || blkno == 0) {
		seq = 1;
		firstblk = blkno;
		return;
	}
prtindir:
	if (seq != 0 && (fs->fs_metaspace == 0 || lastindirblk == 0))
		lastindirblk = lastblk;
	printf("%s-level indirect, blkno %jd-%jd%s\n", indirname[-lastlbn],
	    (intmax_t)blkno, (intmax_t)(blkno + numblks - 1),
	    distance(fs, lastindirblk, blkno));
	lastindirblk = blkno + numblks - 1;
	if (fs->fs_metaspace == 0)
		lastblk = lastindirblk;
	seq = 0;
}
