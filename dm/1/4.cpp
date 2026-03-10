#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> disc;
vector<int> low;
vector<bool> visited;
int timer = 0;
int bridges = 0;

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    
    for (int v : adj[u]) {
        if (v == parent) continue; 
        
        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > disc[u]) {
                bridges++;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    disc.assign(N, 0);
    low.assign(N, 0);
    visited.assign(N, false);
    
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    cout << bridges << endl;
    return 0;
}
