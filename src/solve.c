#include <math.h>
#include <stdlib.h>

#include "../include/interpolation.h"

double lagrangeInterpolation(struct Pair *pairs, int size, double xe) {
  double result = 0;

  for (int i = 0; i < size; i++) {
    double term = pairs[i].second;
    for (int j = 0; j < size; j++) {
      if (i != j) {
        term *= (xe - pairs[j].first) / (pairs[i].first - pairs[j].first);
      }
    }
    result += term;
  }

  return result;
}

double newtonInterpolation(struct Pair *pairs, int size, double xe) {
  double dividedDifferences[size][size];
  double result = 0;

  // Calculate divided differences - DP
  for (int i = 0; i < size; i++) {
    dividedDifferences[i][0] = pairs[i].second;
  }

  for (int j = 1; j < size; j++) {
    for (int i = 0; i < size - j; i++) {
      dividedDifferences[i][j] =
          (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) /
          (pairs[i + j].first - pairs[i].first);
    }
  }

  double term = 1.0;
  for (int i = 0; i < size; i++) {
    result += term * dividedDifferences[0][i];
    term *= (xe - pairs[i].first);
  }

  return result;
}
