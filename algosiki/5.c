#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(8 * sizeof(int));
    int *b = malloc(8 * sizeof(int));
    
    for (int i = 0; i < 8; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 8; i++) scanf("%d", &b[i]);
    
    int* pairs = malloc(8 * sizeof(int));
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((a[i] == b[j]) && (pairs[j] == 0)) {
                pairs[j] = 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (pairs[i] == 0) {
            printf("no");
            return 0;
        }
    }
    
    printf("yes");
    return 0;
}
