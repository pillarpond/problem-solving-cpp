//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

pair<int,int> bfs(int start, const vector<vector<pair<int,int> > > &g) {
    vector<bool> visited(g.size(), false);
    vector<int> dist(g.size(), 0);

    visited[start] = true;
    int max = 0;
    int pos = -1;
    
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for (auto p : g[parent]) {
            int child, cost;
            tie(child, cost) = p;

            if (visited[child]) continue;
            dist[child] = dist[parent] + cost;
            visited[child] = true;
            q.push(child);
            
            if (dist[child] > max) {
                max = dist[child];
                pos = child;
            }
        }
    }
    return {max, pos};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<pair<int,int> > > g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    auto p = bfs(1, g);
    p = bfs(p.second, g);

    cout << p.first << "\n";
    return 0;
}