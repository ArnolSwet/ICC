/* COGNOM1:CIRERA COGNOM2:BOSCH NOM:ARNAU DNI:47988004E */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
    int n, i, j, k;
    double **a, *b, *x;
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
    resTsup (n, a, b, x)

    for (i = 0; i < n; i++)
        free (a[i]);
    free (a);
    free (b);
    free (x);
    return 0;
}
