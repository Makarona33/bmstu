#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs_reverse(int v, const vector<vector<int>>& rev_graph, vector<bool>& visited, vector<int>& finish_order) {
    visited[v] = true;
    for (int n : rev_graph[v]) {
        if (!visited[n]) {
            dfs_reverse(n, rev_graph, visited, finish_order);
        }
    }
    finish_order.push_back(v);
}

void dfs_scc(int v, int comp_id, const vector<vector<int>>& graph, vector<int>& comp) {
    comp[v] = comp_id;
    for (int n : graph[v]) {
        if (comp[n] == -1) {
            dfs_scc(n, comp_id, graph, comp);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<int>> rev_graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> finish_order;

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs_reverse(v, rev_graph, visited, finish_order);
        }
    }

    vector<int> comp(n, -1);
    int comp_cnt = 0;

    for (int i = n - 1; i >= 0; --i) {
        int v = finish_order[i];
        if (comp[v] == -1) {
            dfs_scc(v, comp_cnt, graph, comp);
            ++comp_cnt;
        }
    }

    vector<set<int>> cond_adj(comp_cnt);

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (comp[u] != comp[v]) {
                cond_adj[comp[u]].insert(comp[v]);
            }
        }
    }

    vector<int> indeg(comp_cnt, 0);

    for (int c = 0; c < comp_cnt; ++c) {
        for (int to : cond_adj[c]) {
            indeg[to]++;
        }
    }

    vector<int> base_comps;
    for (int c = 0; c < comp_cnt; ++c) {
        if (indeg[c] == 0) {
            base_comps.push_back(c);
        }
    }

    vector<int> answer;
    for (int c : base_comps) {
        int min_vertex = n;
        for (int v = 0; v < n; ++v) {
            if (comp[v] == c && v < min_vertex) {
                min_vertex = v;
            }
        }
        answer.push_back(min_vertex);
    }

    sort(answer.begin(), answer.end());
    for (size_t i = 0; i < answer.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << answer[i];
    }
    cout << endl;

    return 0;
}
