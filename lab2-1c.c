#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

float poli(float, float[]);
float horner(float, float[]);

int main(void) {
  int i, m, k;
  float a, b, x, aval1, aval2, h;
  float coef[8];
  FILE *entrada, *sortida;
  
  char nom_fitxer[80];
  printf("# Doneu el nom del fitxer d'entrada\n");
  k = scanf("%s", nom_fitxer);
  entrada = fopen(nom_fitxer, "r");
  if (entrada == NULL){
    printf("Error en obrir el fitxer %s\n" , nom_fitxer);
    return 1;
  }
  for (i = 0; i < 8; i++){
    k = fscanf(entrada, "%f", &coef[i]);
  }
  fclose(entrada);
  printf("# Doneu a , b , m = \n");
  k = scanf(" %f %f %d" , &a , &b , &m );
  h = (b-a)/m;
  
  printf("# Doneu el nom del fitxer de sortida\n");
  k = scanf("%s", nom_fitxer);
  sortida = fopen(nom_fitxer, "w+");
  if (sortida == NULL){
    printf("Error en obrir el fitxer %s\n" , nom_fitxer);
    return 1;
  }
  
  fprintf(sortida,
    "# %8s %17s %17s %17s\n" , "x", "poli", "horner", "diferencia");
  for (i = 0; i <= m; i++){
    x = a+i*h;
    aval1 = poli(x, coef);
    aval2 = horner(x, coef);
    fprintf(sortida,
      "%15.6e %15.6e %15.6e %15.6e\n", x,aval1,aval2, fabs(aval1-aval2));
  }
  fclose(sortida);
  return 0;
}

float poli(float z, float a[]){
  int i;
  float sum;
  sum = a[0];
  for (i = 1; i <= 7; i++){
    sum = sum + a[i]*pow(z, i);
  }
  return sum;
}

float horner(float z, float a[]){
  int i;
  float sum;
  sum = a[7];
  for (i = 6; i >= 0; i--){
    sum = sum*z + a[i];
  }
  return sum;
}
