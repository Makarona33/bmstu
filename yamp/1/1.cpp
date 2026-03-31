#include <iostream>
using namespace std;

int main() {
    unsigned long long k;
    cin >> k;
    k--;

    unsigned long long len = 1; 
    unsigned long long count = 9; 
    unsigned long long start = 1; 

    while (k >= len * count) {
        k -= len * count; 
        len++;
        count *= 10;
        start *= 10;
    }

    unsigned long long num = start + k / len; 
    unsigned long long pos = k % len;
    
    for (unsigned long long i = 0; i < len - pos - 1; i++) num /= 10;
    
    unsigned long long ans = num % 10;

    cout << ans << endl;

    return 0;
}
