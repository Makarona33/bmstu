#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int n, x0;
    scanf("%d %d", &n, &x0);
    
    int *koefs = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
         scanf("%d", &koefs[i]);
    }
    
    int p = koefs[0];
    int dp = 0;
    for (int i = 1; i < n; i++) {
        dp = dp*x0 + p;
        p = p*x0 + koefs[i];
    }
    
    printf("%d\n%d", p, dp);
    
    return 0;
}
