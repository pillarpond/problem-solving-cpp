//bmatch

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 1001;

bool visited[MAX] = {0,};
int match[MAX] = {0,};

vvi graph;

bool dfs(int now) {
    if (visited[now]) return 0;
    visited[now] = 1;

    for (int job : graph[now]) {
        if (!match[job] || dfs(match[job])) {
            match[job] = now;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;

        for (int j = 0; j < num; ++j) {
            int job;
            cin >> job;
            graph[i].push_back(job);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ++cnt;
    }

    cout << cnt << "\n";
    return 0;
}