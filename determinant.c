/*
 * determinant d'una matriu per elim. gaussiana amb piv. maximal per columnes
 */
double determinant (double **, int, double);

int main (void) {
  double **a, det, tol;
  int i, j, n=8; /* el NIUB te 8 xifres */

  if ((a = (double **) malloc (n * sizeof (double *))) == NULL) {
    printf )"falta memoria per a\n");
    return 1;
  }
  for (i = 0; i<n; i++)
    if ((a[i]) = (double *) malloc (n * sizeof (double))) == NULL) {
      printf ("falta memoria per a[%d]\n", i);
      return 1;
    }
  for (i = 0; i<n; i++)
    for (j=0; j<n; j++) {
      a[i][j] = abs (i-j);    /* Per exemple */
    }
  /* Omplim la primera fila amb el NIUB (podria ser la 1a columna) */
    for (j = 0; j<n; j++) {
        printf ("num del NIUB?");
        scanf ("%le", &a[0][j]);
        printf ("\n");
    }
    printf ("tol?");
    scanf("%le", &tol);

    for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            printf ("%7.4f ", a[i][j]);
        }
        printf ("\n");
    }

    printf ("det = %23.15e\n", 32 * (6 * a[0][0] - 7 * a[0][1] - a[0][7]));
    det = determinant(a,n,tol);
    printf ("det = %23.15e\n", det);
    for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            printf ("%7.4f ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

double determinant(double **a, int n, double tol) {
    int i, j, k;
    double aux, det = 1., *c;

    for (i = 0; i<n; i++) {
        /* Cerquem element de modul maxim de entre a[i][i], ...., a[n-1][i] */
        k = i;
        aux = fabs (a[i][i]);
        for (j = i + 1; j<n; j++) {
            if (fabs (a[j][i]) > aux) {
                aux = fabs (a[j][i]);
                k = j;
            }
        }

        /* Si tota la columna val 0, la matriu es singular */
        if (aux<tol) {
            return 0.;
        }

        /* Permutem les files i i k amb a[k][i] = max a[j][i], j=i,..,n-1 */
        if (k>i) {
            c = a[i];
            a[i] = a[k];
            a[k] = c;
            /* Si permutem files el determinant canvia de signe */
            det = -det;
        }
        det = det * a[i][i];
        /*un pas mes de gauss */
        for (k = i + 1; k<n; k++) {
            aux = a[k][i] / a[i][i];
            for (j=i; j<n; j++) {
                a[k][j] -= a[i][j] * aux;
            }
        }
    }

    return det;
}
