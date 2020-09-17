//dijkstra

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;

void dijk(int s, vector<vector<pair<int,int> > > &g, vector<int> &cost) {
    priority_queue<pair<int,int> > q;
    q.push({0, s});
    cost[s] = 0;

    while(!q.empty()) {
        auto p = q.top();
        q.pop();

        int dist = -p.first;
        int curr = p.second;

        if (dist > cost[curr]) continue;
        for (auto u : g[curr]) {
            if (cost[curr] + u.first < cost[u.second]) {
                cost[u.second] = cost[curr] + u.first;
                q.push({-cost[u.second], u.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int,int> > > g(V);
    vector<int> cost(g.size(), INF);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({w, v - 1});
    }

    dijk(K - 1, g, cost);
    for (int i = 0; i < V; ++i) {
        if (cost[i] >= INF) cout << "INF\n";
        else cout << cost[i] << "\n";
    }
    return 0;
}