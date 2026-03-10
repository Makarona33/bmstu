#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge& other) const { return w < other.w; }
};


bool dfs(int a, int b, const vector<vector<int>>& forest, vector<bool>& visited) {
    if (a == b) return true;
    visited[a] = true;
    for (int i : forest[a]) {
        if (!visited[i]) {
            if (dfs(i, b, forest, visited)) return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> coords(N);
    for (int i = 0; i < N; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }

    vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            double dx = coords[i].first - coords[j].first;
            double dy = coords[i].second - coords[j].second;
            edges.push_back({i, j, sqrt(dx*dx + dy*dy)});
        }
    }
    sort(edges.begin(), edges.end());

    vector<vector<int>> forest(N);
    double total = 0;
    int c = 0;
    for (const Edge& e : edges) {
        
        vector<bool> visited(N, false);
        if (!dfs(e.u, e.v, forest, visited)) {
            total += e.w;
            forest[e.u].push_back(e.v);
            forest[e.v].push_back(e.u);
            c++;
            if (c == N-1) break;
        }
    }

    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
