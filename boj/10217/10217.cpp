//dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr int INF = 987654321;

int dijk(const vector<vector<tuple<int,int,int> > > &g, int N, int M) {
    vector<vector<int> > cache(N, vector<int>(M + 1, INF));
    priority_queue<tuple<int,int,int> > pq;

    cache[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int dist, curr, cost;
        tie(dist, curr, cost) = pq.top();
        pq.pop();

        if (cache[curr][cost] < -dist) continue;

        for (auto p : g[curr]) {
            int next = get<0>(p);
            int nextcost = cost + get<1>(p);
            int nextdist = -dist + get<2>(p);

            if (M >= nextcost && cache[next][nextcost] > nextdist) {
                cache[next][nextcost] = nextdist;
                pq.push({-nextdist, next, nextcost});
            }
        }
    }

    int res = INF;
    for (const auto val : cache[N - 1]) res = min(res, val);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<tuple<int,int,int> > > g(N);

        for (int i = 0; i < K; ++i) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;

            g[u - 1].push_back({v -1, c, d});
        }

        int res = dijk(g, N, M);
        if (res >= INF) cout << "Poor KCM\n";
        else cout << res << "\n";
    }

    return 0;
}