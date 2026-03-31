#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    int n, x;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums[i] = to_string(x);
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    for (const string &s : nums) cout << s;
    cout << endl;
    
    return 0;
}
