#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *obtenir_fitxer(char*);
int llegir_fitxer(float**);
void escriure_fitxer(float);

int main(void) {
  int nx, ny, i;
  float *x, *y, prod;
  
  printf("Doneu el nom del fitxer amb els elements de x:\n");
  nx = llegir_fitxer(&x);
  printf("Doneu el nom del fitxer amb els elements de y:\n");
  ny = llegir_fitxer(&y);
  if (nx != ny) {
    printf("Les dimensions dels vectors no coincideixen\n");
    return 1;
  }
  
  prod = 0.f;
  for (i = 0; i < nx; i++)
    prod += x[i]*y[i];
  
  printf("Deseu el valor del producte escalar a:\n");
  escriure_fitxer(prod);
  
  free(x);
  free(y);
  return 0;
}

int llegir_fitxer(float **v)
{
  FILE *filet = obtenir_fitxer("r");
  int ch, i, n = 0;
  
  while (EOF != (ch = fgetc(filet)))
    if (isspace(ch)) n++;
  if (n <= 0) {
    printf("El fitxer no conté un vector vàlid\n");
    fclose(filet);
    exit(1);
  }
  
  *v = calloc(n, sizeof(float));
  rewind(filet);
  for (i = 0; i < n; i++)
    fscanf(filet, "%f", *v+i);
  
  fclose(filet);
  return n;
}

void escriure_fitxer(float v)
{
  FILE *filet = obtenir_fitxer("w+");
  fprintf(filet, "%f\n", v);
  fclose(filet);
}

FILE* obtenir_fitxer(char *mode)
{
  FILE *filet;
  char *filename = calloc(FILENAME_MAX, sizeof(char));
  
  fgets(filename, FILENAME_MAX, stdin);
  strtok(filename, "\n");
  
  filet = fopen(filename, mode);
  free(filename);
  
  if (NULL == filet) {
    printf("No es pot accedir al fitxer.\n", filename);
    exit(1);
  }
  return filet;
}
