//floyd-warshall

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

void fw(vector<vector<int> > &dist) {
    int n = dist.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dist[j][i] != INF && dist[i][k] != INF)
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > dist(n, vector<int>(n,INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0; 

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (dist[a - 1][b - 1] > c) dist[a - 1][b - 1] = c;
    }

    fw(dist);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}