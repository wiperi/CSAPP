int mulvec_count = 0;

int mulvec(int *x, int *y, int *z, int n) {
    int i;
    mulvec_count++;
    for (i = 0; i < n; i++) {
        z[i] = x[i] * y[i];
    }
    return mulvec_count;
}