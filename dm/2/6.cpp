#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = map[0][0];

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;
    pq.push({dist[0][0], {0, 0}});

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cur_dist != dist[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int new_dist = cur_dist + map[nx][ny];
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    pq.push({new_dist, {nx, ny}});
                }
            }
        }
    }

    cout << dist[n-1][n-1] << endl;

    return 0;
}
