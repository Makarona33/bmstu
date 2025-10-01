#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void) {
    int size_a, size_b, t;
    int a = 0b0, b = 0b0;
    
    scanf("%d", &size_a);
    for (int i = 0; i < size_a; i++) {
        scanf("%d", &t);
        a += (int)pow(2, t);
    }
    
    scanf("%d", &size_b);
    for (int i = 0; i < size_b; i++) {
        scanf("%d", &t);
        b += (int)pow(2, t);
    }
    
    int c = a & b;

    for (int i = 0; i < 32; i++) {
        if ((1 & c) == 1) printf("%d ", i);
        c >>= 1;
    }
    return 0;
}
