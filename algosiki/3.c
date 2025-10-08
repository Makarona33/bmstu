#include <stdio.h>
#include <stdlib.h>

int main() {
 int x, size = 2;
 scanf("%d", &x);
 
 int *arr = malloc(2 * sizeof(int));
 arr[0] = 1;
 arr[1] = 1;
 while (arr[size - 1] + arr[size - 2] - 1 < x) {
     size += 1;
     arr = realloc(arr, size * sizeof(int));
     arr[size - 1] = arr[size - 2] + arr[size - 3];
 }
 
 for (int i = size - 1; i > 0; i--) {
     if (arr[i] <= x) {
         x -= arr[i];
         printf("1");
     }
     else printf("0");
 }
}
