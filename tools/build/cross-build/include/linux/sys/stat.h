#pragma once
/*
 * glibc shipped with Ubuntu 16.04 doesn't include a definition of
 * struct timespec when sys/stat.h is included
 * */
#define __need_timespec
#include <time.h>
#include_next <sys/stat.h>

#define st_atimensec st_atim.tv_nsec
#define st_mtimensec st_mtim.tv_nsec
#define st_ctimensec st_ctim.tv_nsec

#define st_atimespec st_atim
#define st_mtimespec st_mtim
#define st_ctimespec st_ctim
