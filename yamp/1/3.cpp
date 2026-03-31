#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    char x, y;
    cin >> s >> x >> y;

    int last_x = -1, last_y = -1;
    int dist = 1000000;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == x) {
            last_x = i;
            if (last_y != -1) {
                dist = min(dist, abs(last_x - last_y) - 1);
            }
        } 
        if (s[i] == y) {
            last_y = i;
            if (last_x != -1) {
                dist = min(dist, abs(last_x - last_y) - 1);
            }
        }
    }

    cout << dist << endl;
    return 0;
}
