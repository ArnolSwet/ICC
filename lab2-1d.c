#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

double poli(double, double[]);
double horner(double, double[]);

int main(void) {
  int i, m, k;
  double a, b, x, aval1, aval2, h;
  double coef[8];
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
    k = fscanf(entrada, "%lf", &coef[i]);
  }
  fclose(entrada);
  printf("# Doneu a , b , m = \n");
  k = scanf(" %lf %lf %d" , &a , &b , &m );
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
      "%20.13le %20.13le %20.13le %20.13le\n", x,aval1,aval2, fabs(aval1-aval2));
  }
  fclose(sortida);
  return 0;
}

double poli(double z, double a[]){
  int i;
  double sum;
  sum = a[0];
  for (i = 1; i <= 7; i++){
    sum = sum + a[i]*pow(z, i);
  }
  return sum;
}

double horner(double z, double a[]){
  int i;
  double sum;
  sum = a[7];
  for (i = 6; i >= 0; i--){
    sum = sum*z + a[i];
  }
  return sum;
}
