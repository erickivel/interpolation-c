#include <sys/time.h>

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

struct Pair {
  double first;
  double second;
};

struct Pair *createPairsVector(int size);

void readPairs(struct Pair *pairs, int size);

double lagrangeInterpolation(struct Pair *pairs,int size, double xe);

double newtonInterpolation(struct Pair *pairs,int size, double xe);

void printTime(struct timeval start, struct timeval end);

void freePairsVector(struct Pair *pairs);

#endif
