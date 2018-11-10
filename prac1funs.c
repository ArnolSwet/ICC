/* COGNOM1:CIRERA COGNOM2:BOSCH NOM:ARNAU DNI:47988004E */
#include <stdio.h>
#include <stdlib.h>
#include "prac1funs.h"

int resTsup (int n, double **A, double *b, double *x, double tol) {

  double sum;

  for (i = n-1; i >= 0; i--) {
      sum = 0.0;
      for (k=i+1; k<n; k++)
          sum += A[i][k]*x[k];
      x[i] = (b[i]-sum)/A[i][i];
  }
  printf("\nEl vector solució és: \n");
  for (i = 0; i < n; i++)
      printf("x(%d)= %lf\n", i, x[i]);
}
