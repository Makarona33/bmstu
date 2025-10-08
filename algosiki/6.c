#include <stdio.h>
#include <stdlib.h>

int main() {
 int k, size, s = 0, max_s = 0;
 scanf("%d %d", &k, &size);
 
 int *arr = malloc(size * sizeof(int));
 
 for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
 
 for (int i = 0; i < size; i++) {
     if (i < k) {
         s += arr[i];
     }
     else {
         s += arr[i];
         s -= arr[i-k];
     }
     
     if (s > max_s) max_s = s;
 }
 
 printf("%d", max_s);

}
