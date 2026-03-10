#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


vector<unsigned int> divisors;
set<pair<unsigned int, unsigned int>> edges;

void find_edges(unsigned int a, unsigned int b) {
    if (a % b != 0 || a == b) return;
    bool has_intermediate = false;
    for (unsigned int w : divisors) {
        if (w > b && w < a && a % w == 0 && w % b == 0) {
            find_edges(w, b);
            has_intermediate = true;
        }
    }
    if (!has_intermediate) edges.insert({a, b});
}

int main() {
    unsigned int x;
    cin >> x;

    for (unsigned int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) divisors.push_back(x / i);
        }
    }
    
    std::sort(divisors.begin(), divisors.end(), greater<int>());  
    
    for (unsigned int d : divisors) if (d != x) find_edges(x, d);
        
    int n = divisors.size();
    for (int i = 0; i < n; ++i) cout << divisors[i] << " ";
    cout << "\n";
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (edges.count({divisors[i], divisors[j]}) || edges.count({divisors[j], divisors[i]}))
                cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}
