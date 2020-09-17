//dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr int INF = 987654321;

int dijk(int s, int e, vector<vector<pair<int,int> > > &g) {
    vector<int> dist(g.size(), INF);
    priority_queue<pair<int,int> > pq;
    pq.push({0, s - 1});
    dist[s - 1] = 0;

    while (!pq.empty()) {
        int cost, curr;
        tie(cost, curr) = pq.top();
        pq.pop();

        if (dist[curr] < -cost) continue;
        
        for (auto next : g[curr]) {
            if (dist[next.first] > -cost + next.second) {
                pq.push({cost - next.second, next.first});
                dist[next.first] = -cost + next.second;
            }
        }
    }
    return dist[e - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int> > > g(N);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
        g[b - 1].push_back({a - 1, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    unsigned long long ans1, ans2;

    ans1 = dijk(1, v1, g) + dijk(v1, v2, g) + dijk(v2, N, g);
    ans2 = dijk(1, v2, g) + dijk(v2, v1, g) + dijk(v1, N, g);

    if (min(ans1, ans2) >= INF) cout << "-1\n";
    else cout << min(ans1, ans2) << "\n";

    return 0;
}