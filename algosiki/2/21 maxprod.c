#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    size_t n;
    if (scanf("%zu", &n) != 1) {
        return EXIT_FAILURE;
    }    
    double *array = malloc(n * sizeof(double));
    for (size_t i = 0; i < n; ++i) {
        int numerator, denominator;
        if (scanf("%d/%d", &numerator, &denominator) != 2) {
            free(array);
            return EXIT_FAILURE;
        } 
        array[i] = (double) numerator / denominator;
    }
    
    double cur_prod = array[0];
    double best_prod = array[0];

    size_t cur_start = 0, cur_end = 0, best_start = 0, best_end = 0;

    for (size_t i = 1; i < n; ++i) {
        cur_prod = cur_prod * array[i];
        if (cur_prod < array[i]) {
            cur_prod = array[i];
            cur_start = i;
        } else {
            cur_end = i;
        }
        if (best_prod < cur_prod) {
            best_start = cur_start;
            best_end = cur_end;
            best_prod = cur_prod;
        }
    }

    printf("%zu %zu", best_start, best_end);
    free(array);
    return EXIT_SUCCESS;
}
