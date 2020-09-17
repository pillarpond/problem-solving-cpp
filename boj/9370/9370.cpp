//dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr int INF = 987654321;

int dijk(int s, int e, const vector<vector<pair<int,int> > > &graph) {
    priority_queue<pair<int,int> > pq;
    pq.push({0, s - 1});

    vector<int> dist(graph.size(), INF);
    dist[s - 1] = 0;

    while (!pq.empty()) {
        int cost, curr;
        tie(cost, curr) = pq.top();
        pq.pop();

        if (dist[curr] < -cost) continue;

        for (const auto next : graph[curr]) {
            if (dist[next.first] > -cost + next.second) {
                dist[next.first] = -cost + next.second;
                pq.push({cost - next.second, next.first});
            }
        }
    }
    return dist[e - 1];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pair<int,int> > > v(n);
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;

            v[a - 1].push_back({b - 1, d});
            v[b - 1].push_back({a - 1, d});
        }

        priority_queue<int> q;
        for (int i = 0; i < t; ++i) {
            int e;
            cin >> e;
            int res = dijk(s, e, v);
            int ans1 = dijk(s, g, v) + dijk(g, h, v) + dijk(h, e, v);
            int ans2 = dijk(s, h, v) + dijk(h, g, v) + dijk(g, e, v);

            if (res == ans1 || res == ans2) q.push(-e);
        }

        while (!q.empty()) {
            cout << -q.top() << " ";
            q.pop();
        }
        cout << "\n";
    }
    return 0;
}