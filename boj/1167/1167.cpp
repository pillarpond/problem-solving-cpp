//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

pair<int,int> bfs(int start, const vector<vector<pair<int, int> > > &g, vector<int> &dist) {
    vector<bool> visited(g.size(), false);
    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    int max = 0;
    int pos = -1;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto p : g[curr]) {
            int next, cost;
            tie(next, cost) = p;
            
            if (visited[next]) continue;
            visited[next] = true;
            dist[next] = dist[curr] + cost;
            q.push(next);

            if (dist[next] > max) {
                max = dist[next];
                pos = next;
            }
        }
    }
    return {max, pos};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    cin >> V;

    vector<vector<pair<int,int> > > g(V + 1);
    vector<int> dist(V + 1, 0);
    
    for (int i = 0; i < V; ++i) {
        int start, end, cost;
        cin >> start >> end;
        
        while (end != -1) {
            cin >> cost;
            g[start].push_back({end, cost});
            cin >> end;
        }
    }

    auto p = bfs(1, g, dist);
    p = bfs(p.second, g, dist);
    cout << p.first << "\n";
}