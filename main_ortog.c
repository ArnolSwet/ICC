#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float prod_esc(int, float *, float *);

int main()
{
  int i, n;
  float tol, *x, *y;
  
  printf("Insereix la dimensió dels vectors:\n");
  scanf("%d", &n);
  if (n <= 0) {
    printf("No has donat un paràmetre correcte.\n");
    return 1;
  }
  
  x = calloc(n, sizeof(float));
  printf("Introduïu el vector x:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &x[i]);
  
  y = calloc(n, sizeof(float));
  printf("Introduïu el vector y:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &y[i]);
  
  printf("Introduïu la tolerància:\n");
  scanf("%f", &tol);
  
  printf("Els vectors donats ");
  if (fabsf(prod_esc(n, x, y)) >= tol)
    printf("no ");
  printf("són ortogonals (amb aquesta tolerància)\n");
  
  free(x);
  free(y);
  return 0;
}
