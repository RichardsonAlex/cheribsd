#!/bin/ksh -p
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#

#
# Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
# ident	"%Z%%M%	%I%	%E% SMI"
#

if [ $# != 1 ]; then
	echo expected one argument: '<'dtrace-path'>'
	exit 2
fi

dtrace=$1

$dtrace -wZq -x switchrate=100ms -s /dev/stdin <<EOF
pid*:date::
{
	printf("%s:%s\n", probefunc, probename);
}

tick-1s
/i++ > 5/
{
	exit(0);
}

tick-1s
/(i % 2) == 0/
{
	system("dtrace -c date -ln 'pid\$target::main:entry' >/dev/null");
}

tick-1s
/(i % 2) == 1/
{
	system("dtrace -c date -ln 'pid\$target::main:return' >/dev/null");
}
EOF

exit $status
