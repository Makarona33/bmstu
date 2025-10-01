#include <stdio.h>
#include <stdlib.h>


int binsearch(int *arr, int lenth, int n) {
    int left = 0, right = lenth-1, mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (arr[mid] == n) return mid;
        
        if (arr[mid] < n) left = mid + 1;
        else right = mid - 1;
    }
    
    return lenth;
}


int main(void) {
    int len, number;
    scanf("%d %d", &len, &number);
    
    int *arr = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);

    int res = binsearch(arr, len, number);
    printf("%d", res);
    
    return 0;
}
