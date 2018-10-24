/*  Funcion para resolver un sistema triangular superior */
/*  usando memoria dinámica */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
    int n, i, j, k;
    double **a, *b, *x, *y, sum;
    printf("Numero de ecuaciones: ");
    scanf("%d", &n);
    a = (double **) malloc (n * sizeof (double *));
    if (a == NULL) {
        printf ("No hi ha prou memoria\n");
        exit (1);
    }
    for (i = 0; i < n; i++) {
        a[i] = (double *) malloc (n * sizeof (double));
        if (a[i] == NULL) {
            printf ("No hi ha prou memoria\n");
            exit (2);
        }
    }
    b = (double *) malloc (n * sizeof (double));
    x = (double *) malloc (n * sizeof (double));
    if (b == NULL || x == NULL) {
        printf ("No hi ha prou memoria\n");
        exit (3);
    }
    printf("\nMatriz del sistema:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
    printf("a(%d, %d): ", i+1, j+1);
    scanf("%lf", &a[i][j]);
    }
    printf("\n\nTerminos independientes:\n");
    for (i = 0; i < n; i++) {
        printf("b(%d): ", i+1);
        scanf("%lf", &b[i]);
    }
    for (i = n-1; i >= 0; i--) {
        sum = 0.0;
        for (k=i+1; k<n; k++)
            sum += a[i][k]*x[k];
        x[i] = (b[i]-sum)/a[i][i];
    }
    printf("\nEl vector solucion es: \n");
    for (i = 0; i < n; i++)
        printf("x(%d)= %lf\n", i, x[i]);

    for (i = 0; i < n; i++) {
        sum = 0.0;
        for (j = 0; j < n; j++)
            sum += a[i][j] * x[j];
        y[i] = sum - b[i];
    }
    printf("\nEl vector y es: \n");
    for (i = 0; i < n; i++)
        printf("y(%d)= %lf\n", i, y[i]);

    for (i = 0; i < n; i++)
        free (a[i]);
    free (a);
    free (b);
    free (x);
    return 0;
}

