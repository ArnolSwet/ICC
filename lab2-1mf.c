#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef float real;

real poli(real, real*);
real horner(real, real*);

int main(
  int argc, char **argv
){
  int i, m, k;
  real a, b, x, a1, a2, h;
  real coef[8];
  
  FILE *input;
  input = fopen(argv[1], "r");
  if (NULL == input) {printf("(-) Non-existent file.\n"); return 1;}
  for (i = 0; i < 8; i++)
    k = fscanf(input, "%f", coef+i);
  fclose(input);
  
  a = strtof(argv[2], NULL);
  b = strtof(argv[3], NULL);
  m = atoi(argv[4]);
  h = (b-a)/m;
  
  printf("#%8s %17s %17s %17s\n", "x", "poli", "horner", "diferencia");
  for (i = 0; i <= m; i++) {
    x = a + i*h;
    a1 = poli(x, coef);
    a2 = horner(x, coef);
    printf("%15.6e %15.6e %15.6e %15.6e\n", x, a1, a2, fabs(a1-a2));
  }
  return 0;
  
}

real poli(real z, real *a)
{
  real s = a[0];
  for (int i = 1; i <= 7; i++) s = s + a[i]*pow(z, i);
  return s;
}
real horner(real z, real *a)
{
  real s = a[7];
  for (int i = 6; i >= 0; i--) s = s*z + a[i];
  return s;
}
