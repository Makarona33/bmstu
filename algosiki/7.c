#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int x;
    scanf("%d", &x);
    
    // простые числа до x через решето эратосфена
    int* n = malloc((x-1) * sizeof(int));
    for (int i = 0; i < x-1; i++) {
        n[i] = i+2;
    }

    int p = 2, c = 0;
    while (p*p <= x) {
        for (int i = c; i < x-1; i+=p) {
            if (n[i] != p) n[i] = 0;
        }
        
        for (int i = c+1; i < x-1; i++) {
            if (n[i] != 0) {
                p = n[i];
                c = i;
                break;
            }
        }
    }
    
    // поиск наибольшего
    for (int i = x-2; i >= 0; i--) {
        if ((n[i] != 0) && (x % n[i] == 0)) {
            printf("%d", n[i]);
            break;
        }
    }
    
    return 0;
}
