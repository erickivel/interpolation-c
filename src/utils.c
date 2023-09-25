#include <stdio.h>
#include <sys/time.h>

#include "../include/interpolation.h"

void printTime(struct timeval start, struct timeval end) {
  long seconds, useconds;
  seconds = end.tv_sec - start.tv_sec;
  useconds = end.tv_usec - start.tv_usec;

  long mtime = ((seconds * 1000) + useconds);

  printf("%ld\n", mtime);
}
