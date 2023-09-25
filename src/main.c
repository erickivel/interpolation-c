#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../include/interpolation.h"
#include "likwid.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main(int argc, char **args) {
  // Arrange

  double xe = atof(args[1]);
  int size;
  scanf("%d", &size);

  struct timeval start1, start2, end1, end2;

  struct Pair *pairs = createPairsVector(size);

  readPairs(pairs, size);

  int smallest = pairs[0].first;
  int greatest = pairs[0].first;
  for (int i = 1; i < size; i++) {
    smallest = MIN(smallest, pairs[i].first);
    greatest = MAX(smallest, pairs[i].first);
  }

  if (xe < smallest || xe > greatest) {
    fprintf(stderr, "O ponto deve pertencer a tabela de pontos fornecida!\n");
    exit(1);
  }

  LIKWID_MARKER_INIT;

  // Calculate
  LIKWID_MARKER_START("Lagrange");
  gettimeofday(&start1, NULL);
  double lagrangeSolution = lagrangeInterpolation(pairs, size, xe);
  gettimeofday(&end1, NULL);
  LIKWID_MARKER_STOP("Lagrange");

  LIKWID_MARKER_START("Newton");
  gettimeofday(&start2, NULL);
  double newtonSolution = newtonInterpolation(pairs, size, xe);
  gettimeofday(&end2, NULL);
  LIKWID_MARKER_STOP("Newton");

  LIKWID_MARKER_CLOSE;

  // Show
  printf("%lf\n", lagrangeSolution);
  printf("%lf\n", newtonSolution);
  printTime(start1, end1);
  printTime(start2, end2);

  // Free
  freePairsVector(pairs);

  return 0;
}
