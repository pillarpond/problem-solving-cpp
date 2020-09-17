//edmonds-karp

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 2003;
constexpr int src = 0;
constexpr int bridge = 2001;
constexpr int sink = 2002;

int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};
int rev[MAX] = {0,};

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

        for (int i = end; i != start; i = rev[i]) {
            ++f[rev[i]][i];
            --f[i][rev[i]];
        }

        ++ret;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    memset(rev, -1, sizeof(rev));
    graph[src].push_back(bridge);
    graph[bridge].push_back(src);
    c[src][bridge] = K;

    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;

        graph[src].push_back(i);
        graph[i].push_back(src);
        c[src][i] = 1;

        graph[bridge].push_back(i);
        graph[i].push_back(bridge);
        c[bridge][i] = K;

        while(cnt--) {
            int work;
            cin >> work;

            work += 1000;
            c[i][work] = 1;

            graph[i].push_back(work);
            graph[work].push_back(i);

            if (c[work][sink] == 0) {
                graph[work].push_back(sink);
                graph[sink].push_back(work);
                c[work][sink] = 1;
            }
        }
    }

    cout << maxflow(src, sink) << "\n";
    return 0;
}