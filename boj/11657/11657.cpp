//bellman-ford

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

bool bf(const vector<vector<pair<int,int> > > &g, vector<long long> &dist) {
    bool change = false;
    int T = g.size();

    while (T--) {
        for (int i = 0; i < g.size(); ++i) {
            if (dist[i] == INF) continue;

            for (const auto &next : g[i]) {
                long long cost = dist[i] + next.second;
                if (dist[next.first] > cost) {
                    dist[next.first] = cost;
                    change = true;
                }
            }
        }
    }
    return change;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int> > > g(N);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        g[A - 1].push_back({B - 1, C});
    }

    vector<long long> dist(g.size(), INF);
    dist[0] = 0;

    bf(g, dist);

    if (bf(g,dist)) {
        cout << "-1";
    } else {
        for (int i = 1; i < N; ++i) {
            if (dist[i] == INF) cout << "-1 ";
            else cout << dist[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}