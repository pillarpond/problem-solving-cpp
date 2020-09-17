//scc

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 100001;

vvi graph;
vvi rgraph;

int cnt = 0;
int sccidx[MAX] = {0,};
int indegree[MAX] = {0,};

bool visited[MAX] = {0,};

stack<int> s;

void dfs(int now) {
    visited[now] = true;

    for (int next : graph[now]) {
        if (!visited[next]) dfs(next);
    }
    s.push(now);
}

void scc(int now) {
    visited[now] = true;
    sccidx[now] = cnt;

    for (int next : rgraph[now]) {
        if (!visited[next]) scc(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        memset(visited, 0, sizeof(visited));
        memset(sccidx, 0, sizeof(sccidx));
        memset(indegree, 0, sizeof(indegree));

        graph.clear();
        rgraph.clear();

        int N, M;
        cin >> N >> M;

        graph.resize(N + 1);
        rgraph.resize(N + 1);

        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;

            graph[x].push_back(y);
            rgraph[y].push_back(x);
        }

        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) dfs(i);
        }

        memset(visited, 0, sizeof(visited));
        cnt = 0;

        while(!s.empty()) {
            int top = s.top();
            s.pop();

            if (visited[top]) continue;

            scc(top);
            ++cnt;
        }

        for (int i = 1; i <= N; ++i) {
            for (int j : graph[i]) {
                if (sccidx[i] != sccidx[j]) {
                    ++indegree[sccidx[j]];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < cnt; ++i) {
            if (indegree[i] == 0) ++ans;
        }

        cout << ans << "\n";
    }

    return 0;
}