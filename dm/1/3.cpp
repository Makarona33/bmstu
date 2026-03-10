#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<pair<int,int>> edges;
vector<int> comp_id;
vector<int> comp_vertex_count;
vector<int> comp_edge_count;
vector<int> comp_min_vertex;
int comp_amount = 0;

void dfs(int curr_vertex, int curr_comp, int& min_vertex, int& vertex_count) {
    comp_id[curr_vertex] = curr_comp;
    vertex_count++;
    if (curr_vertex < min_vertex) min_vertex = curr_vertex;
    for (int i : adj[curr_vertex]) {
        if (comp_id[i] == -1) dfs(i, curr_comp, min_vertex, vertex_count);
    }
}

int main() {
    cin >> N >> M;
    adj.resize(N);
    edges.resize(M);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    comp_id.assign(N, -1);
    for (int i = 0; i < N; ++i) {
        if (comp_id[i] == -1) {
            int min_v = i, c = 0;
            dfs(i, comp_amount, min_v, c);
            
            comp_vertex_count.push_back(c);
            comp_min_vertex.push_back(min_v);
            comp_edge_count.push_back(0);
            comp_amount++;
        }
    }
    
    for (auto &e : edges) {
        int c = comp_id[e.first];
        comp_edge_count[c]++;
    }
    
    int best = 0;
    for (int c = 1; c < comp_amount; ++c) {
        if ((comp_vertex_count[c] > comp_vertex_count[best]) ||
            (comp_vertex_count[c] == comp_vertex_count[best] && comp_edge_count[c] > comp_edge_count[best]) ||
            (comp_vertex_count[c] == comp_vertex_count[best] && comp_edge_count[c] == comp_edge_count[best] && comp_min_vertex[c] < comp_min_vertex[best])) {
            best = c;
        }
    }
    
    cout << "graph G {\n";
    cout << "    node [shape=circle];\n";
    for (int i = 0; i < N; ++i) {
        cout << "    " << i;
        if (comp_id[i] == best) cout << " [color=red]";
        cout << ";\n";
    }
    for (auto &e : edges) {
        cout << "    " << e.first << "--" << e.second;
        if (comp_id[e.first] == best) cout << " [color=red]";
        cout << ";\n";
    }
    cout << "}\n";
    
    return 0;
}
