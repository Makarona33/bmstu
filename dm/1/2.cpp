#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> color;

struct Component {
    vector<int> color0;
    vector<int> color1;
};
vector<Component> comps;

bool dfs_visit(int curr_vertex, int curr_color, vector<int>& vertices) {
    color[curr_vertex] = curr_color;
    vertices.push_back(curr_vertex);
    
    for (int i : adj[curr_vertex]) {
        if (color[i] == curr_color) return false;
        if (color[i] == -1 && !dfs_visit(i, 1 - curr_color, vertices)) return false;
    }
    
    return true;
}

bool is_bipartite() {
    for (int i = 0; i < N; ++i) {
        if (color[i] == -1) {
            vector<int> vertices;
            if (!dfs_visit(i, 0, vertices)) return false;
            
            vector<int> color0, color1;
            for (int v : vertices) {
                if (color[v] == 0) color0.push_back(v);
                else color1.push_back(v);
            }
            comps.push_back({color0, color1});
        }
    }
    return true;
}

int k;
vector<int> choice;
vector<int> best_first_group;
int best_diff = -1;

bool less_vector(const vector<int>& a, const vector<int>& b) {
    size_t n = min(a.size(), b.size());
    for (size_t i = 0; i < n; ++i) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return a.size() < b.size();
}

void dfs(int idx) {
    if (idx != k) {
        choice[idx] = 0;
        dfs(idx + 1);
        choice[idx] = 1;
        dfs(idx + 1);
        return;
    }
    
    vector<int> group0, group1;
    for (int i = 0; i < k; ++i) {
        if (choice[i] == 0) {
            group0.insert(group0.end(), comps[i].color0.begin(), comps[i].color0.end());
            group1.insert(group1.end(), comps[i].color1.begin(), comps[i].color1.end());
        } else {
            group0.insert(group0.end(), comps[i].color1.begin(), comps[i].color1.end());
            group1.insert(group1.end(), comps[i].color0.begin(), comps[i].color0.end());
        }
    }
    
    int sz0 = group0.size(), sz1 = group1.size();
    int diff = abs(sz0 - sz1);
    
    sort(group0.begin(), group0.end());
    sort(group1.begin(), group1.end());
        
    vector<int> first;
    if (sz0 < sz1) first = group0;
    else if (sz0 > sz1) first = group1;
    else first = less_vector(group0, group1) ? group0 : group1;
    
    if (best_diff == -1 || diff < best_diff || (diff == best_diff && less_vector(first, best_first_group))) {
        best_diff = diff;
        best_first_group = first;
    }
}

int main() {
    cin >> N;
    vector<string> mat(N);
    for (int i = 0; i < N; ++i) cin >> mat[i];

    adj.resize(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mat[i][j] == '+' or mat[i][j] == '1') adj[i].push_back(j);
        }
    }
    
    color.assign(N, -1);
    if (!is_bipartite()) {
        cout << "No solution" << endl;
        return 0;
    }

    k = comps.size();
    choice.resize(k);
    dfs(0);

    for (size_t i = 0; i < best_first_group.size(); ++i) {
        if (i) cout << " ";
        cout << best_first_group[i] + 1;
    }
    cout << endl;

    return 0;
}
