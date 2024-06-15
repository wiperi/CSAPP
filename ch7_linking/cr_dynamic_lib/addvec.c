int addvec_count = 0;

int addvec(int *x, int *y, int *z, int n) {
    int i;
    addvec_count++;
    for (i = 0; i < n; i++) {
        z[i] = x[i] + y[i];
    }
    return addvec_count;
}