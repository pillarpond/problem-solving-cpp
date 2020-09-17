//bmatch

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 501;

bool visited[MAX] = {0,};
int match[MAX] = {0,};

vvi graph;

int dfs(int now) {
    if (visited[now]) return 0;
    visited[now] = true;

    for (int next : graph[now]) {
        if (!match[next] || dfs(match[next])) {
            match[next] = now;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    graph.resize(n + 1);

    for (int i = 0; i < k; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ++cnt;
    }

    cout << cnt << "\n";
    return 0;
}