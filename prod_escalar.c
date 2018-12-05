float prod_esc(
  int n, float *x, float *y
){
  float prod = 0.f;
  for (int i = 0; i < n; i++)
    prod += x[i]*y[i];
  return prod;
}
