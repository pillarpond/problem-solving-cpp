//tree, dfs

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 100000;

int depth[MAX + 1] = {0,};
int ac[MAX + 1][20] = {0,};
vector<vector<int> > graph;
int max_depth;

void dfs(int node, int parent) {
    depth[node] = depth[parent] + 1;
    ac[node][0] = parent;

    for (int i = 1; i <= max_depth; ++i) {
        int a = ac[node][i - 1];
        ac[node][i] = ac[a][i - 1];
    }

    for (int child : graph[node]) {
        if (child != parent) dfs(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    graph.resize(N + 1);
    max_depth = log2(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    depth[0] = -1;
    dfs(1, 0);

    int M;
    cin >> M;

    while (M--) {
        int x, y;
        cin >> x >> y;

        if (depth[x] != depth[y]) {
            if (depth[x] > depth[y]) swap(x, y);

            for(int i = max_depth; i >= 0; --i) {
                if (depth[x] > depth[ac[y][i]]) continue;
                y = ac[y][i];
            }
        }

        int ans = x;

        if (x != y) {
            for (int i = max_depth; i >= 0; --i) {
                if (ac[x][i] != ac[y][i]) {
                    x = ac[x][i];
                    y = ac[y][i];
                }
                ans = ac[x][i];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}