#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, m, q0;
    cin >> n >> m >> q0;

    vector<vector<int>> delta(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> delta[i][j];

    vector<vector<string>> fi(n, vector<string>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> fi[i][j];

    map<pair<int,int>, vector<string>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int to = delta[i][j];
            string label = string(1, 'a' + j) + "(" + fi[i][j] + ")";
            edges[{i, to}].push_back(label);
        }
    }

    cout << "digraph {\n";
    cout << "  start [shape=point];\n";
    for (int i = 0; i < n; ++i) {
        cout << "  " << i << " [shape=circle];\n";
    }
    cout << "  start -> " << q0 << ";\n";

    for (const auto& entry : edges) {
        int from = entry.first.first;
        int to = entry.first.second;
        const vector<string>& labels = entry.second;
        cout << "  " << from << " -> " << to << " [label=\"";
        for (size_t k = 0; k < labels.size(); ++k) {
            if (k > 0) cout << ",";
            cout << labels[k];
        }
        cout << "\"];\n";
    }
    cout << "}\n";

    return 0;
}
