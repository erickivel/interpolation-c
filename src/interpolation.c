#include <stdio.h>
#include <stdlib.h>

#include "../include/interpolation.h"

struct Pair *createPairsVector(int size) {
  struct Pair *pairs = malloc(sizeof(struct Pair)*size);

  return pairs;
}

void readPairs(struct Pair *pairs, int size) {
  for (int i = 0; i < size; i++) {
        scanf("%lf", &pairs[i].first);
        scanf("%lf", &pairs[i].second);
  }
}

void printSolution(double *solution, int size) {
  printf("X = [ ");
  for (int i = 0; i < size; i++) {
    printf("%lf ", solution[i]);
  }
  printf("]\n");
}

void freePairsVector(struct Pair *pairs) {
  free(pairs);
}
