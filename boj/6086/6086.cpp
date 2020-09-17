//edmonds-karp

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 52;

int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};
int visit[MAX];

vvi graph(52);

int maxflow(int start, int end) {
    int ret = 0;
    while(1) {
        memset(visit, -1, sizeof(visit));
        queue<int> q;
        q.push(start);

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

        int flow = 987654321;
        for (int now = end, prev; now != start; now = prev) {
            prev = visit[now];
            flow = min(flow, c[prev][now] - f[prev][now]);
        }

        for (int now = end, prev; now != start; now = prev) {
            prev = visit[now];
            f[prev][now] += flow;
            f[now][prev] -= flow;
        }

        ret += flow;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char a, b;
        int w;
        cin >> a >> b >> w;

        int u = a < 'a' ? a - 'A' : a - 'a' + 26;
        int v = b < 'a' ? b - 'A' : b - 'a' + 26;

        graph[u].push_back(v);
        graph[v].push_back(u);

        c[u][v] += w;
        c[v][u] += w;
    }

    cout << maxflow(0, 25) << "\n";
    return 0;
}