//scc

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 100001;

vvi graph;
vvi rgraph;

bool visited[MAX] = {0,};

stack<int> s;

int cnt;
int sccidx[MAX] = {0,};
int indegree[MAX] = {0,};

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

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        graph.clear();
        rgraph.clear();

        int N, M;
        cin >> N >> M;

        graph.resize(N);
        rgraph.resize(N);

        memset(visited, 0, sizeof(visited));
        memset(indegree, 0, sizeof(indegree));
        memset(sccidx, 0, sizeof(sccidx));

        for (int i = 0; i < M; ++i) {
            int A, B;
            cin >> A >> B;

            graph[A].push_back(B);
            rgraph[B].push_back(A);
        }

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) dfs(i);
        }

        memset(visited, 0, sizeof(visited));
        cnt = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (visited[top]) continue;

            scc(top);
            cnt++;
        }

        for (int i = 0; i < N; ++i) {
            for (int j : graph[i]) {
                if (sccidx[i] != sccidx[j]) ++indegree[sccidx[j]];
            }
        }

        int ans = 0;
        int idx;

        for (int i = 0; i < cnt; ++i) {
            if (indegree[i] == 0) {
                ++ans;
                idx = i;
            }
        }

        if (ans == 1) {
            for (int i = 0; i < N; ++i) {
                if (sccidx[i] == idx) cout << i << "\n";
            }
        } else cout << "Confused\n";
        cout << "\n";
    }

    return 0;
}