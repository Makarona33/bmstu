#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int K;
    cin >> K;
    vector<int> pivots(K);
    for (int i = 0; i < K; ++i) {
        cin >> pivots[i];
    }
    
    vector<vector<int>> dist(K, vector<int>(N, -1));
    for (int i = 0; i < K; ++i) {
        int s = pivots[i];
        queue<int> q;
        q.push(s);
        dist[i][s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) {
                if (dist[i][u] == -1) {
                    dist[i][u] = dist[i][v] + 1;
                    q.push(u);
                }
            }
        }
    }
    
    vector<int> ans;
    for (int u = 0; u < N; ++u) {
        int d = dist[0][u];
        if (d == -1) continue;
        bool flag = true;
        for (int i = 1; i < K; ++i) {
            if (dist[i][u] != d) {
                flag = false;
                break;
            }
        }
        if (flag) ans.push_back(u);
    }
    
    if (ans.empty()) {
        cout << "-";
    } else {
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << " ";
            cout << ans[i];
        }
    }
    cout << endl;
    
    return 0;
}
