#include <stdio.h>
#include <sys/time.h>

#include "../include/interpolation.h"
//#include <likwid.h>

int main(char* args, int argc) {
  // Arrange
  
  double xe = atof(args[1]);
  int size;
  scanf("%d", &size);

  struct timeval start1, start2, end1, end2;

  struct Pair *pairs = createPairsVector(size);

  readPairs(pairs, size);

  //LIKWID_MARKER_INIT;

  // Calculate
  //LIKWID_MARKER_START("Sol_1");
  gettimeofday(&start1, NULL);
  double newtonSolution = newtonInterpolation(pairs, size, xe);
  gettimeofday(&end1, NULL);
  //LIKWID_MARKER_STOP("Sol_1");

  //LIKWID_MARKER_START("Sol_2");
  gettimeofday(&start2, NULL);
  double lagrangeSolution = lagrangeInterpolation(pairs, size, xe);
  gettimeofday(&end2, NULL);
  //LIKWID_MARKER_STOP("Sol_2");

 //LIKWID_MARKER_CLOSE;

  // Show
  printf("\n");
  printf("Lagrange: %lf\n", lagrangeSolution);
  printTime(start1, end1);
  printf("\n");

  printf("\n");
  printf("Newton: %lf\n", lagrangeSolution);
    printTime(start2, end2);
  printf("\n");

  // Free
  freePairsVector(pairs);

  return 0;
}
