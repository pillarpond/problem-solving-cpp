//edmonds-karp

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 801;

int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};
int rev[MAX];

vvi graph(MAX);

int maxflow(int start, int end) {
    int ret = 0;

    while(1) {
        queue<int> q;
        q.push(start);
        memset(rev, -1, sizeof(rev));

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            for (int next : graph[now]) {
                if (rev[next] != -1) continue;
                if (c[now][next] - f[now][next] > 0) {
                    q.push(next);
                    rev[next] = now;

                    if (next == end) break;
                }
            }
        }

        if (rev[end] == -1) break;

        for (int now = end; now != start; now = rev[now]) {
            f[rev[now]][now] += 1;
            f[now][rev[now]] -= 1;
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

    for (int i = 1; i <= N; ++i) {
        c[i][i + 400] = 1;

        graph[i].push_back(i + 400);
        graph[i + 400].push_back(i);
    }

    while(P--) {
        int u, v;
        cin >> u >> v;

        graph[u + 400].push_back(v);
        graph[v].push_back(u + 400);
        graph[v + 400].push_back(u);
        graph[u].push_back(v + 400);

        c[u + 400][v] = 1;
        c[v + 400][u] = 1;
    }

    cout << maxflow(401, 2) << "\n";
    return 0;
}