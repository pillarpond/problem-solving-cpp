//floyd-warshall

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

void fw(vector<vector<int> > &g) {
    int n = g.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (g[j][k] > g[j][i] + g[i][k]) {
                    g[j][k] = g[j][i] + g[i][k];
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int> > g(V, vector<int>(V, INF));

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a -1][b - 1] = c;
    }

    fw(g);
    int res = INF;
    for (int i = 0; i < V; ++i) res = min(res, g[i][i]);

    if (res == INF) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}