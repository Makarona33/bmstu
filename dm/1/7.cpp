#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < M; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        cost[u][v] = len;
        cost[v][u] = len;
    }

    vector<int> min_e(N, INT_MAX);
    vector<bool> used(N, false);
    min_e[0] = 0;
    long long total = 0;

    for (int i = 0; i < N; ++i) {
        int v = -1;
        for (int j = 0; j < N; ++j) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        }
        
        used[v] = true;
        total += min_e[v];

        for (int j = 0; j < N; ++j) {
            if (!used[j] && cost[v][j] < min_e[j]) {
                min_e[j] = cost[v][j];
            }
        }
    }

    cout << total << endl;
    return 0;
}
