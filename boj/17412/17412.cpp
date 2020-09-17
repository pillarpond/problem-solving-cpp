//edmonds-karp

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 401;

vvi graph;

int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};
int visit[MAX];

int maxflow(int start, int end) {
    int ret = 0;

    while(1) {
        queue<int> q;
        q.push(start);
        memset(visit, -1, sizeof(visit));

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            for (int next : graph[now]) {
                if (visit[next] != -1) continue;
                if (c[now][next] - f[now][next] > 0) {
                    q.push(next);
                    visit[next] = now;
                    
                    if (next == end) break;
                }
            }
        }

        if (visit[end] == -1) break;

        for (int now = end, prev; now != start; now = prev) {
            prev = visit[now];
            f[prev][now] += 1;
            f[now][prev] -= 1;
        }

        ++ret;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P;
    cin >> N >> P;

    graph.resize(N + 1);

    while(P--) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        c[u][v] = 1;
    }

    cout << maxflow(1, 2) << "\n";
    return 0;
}