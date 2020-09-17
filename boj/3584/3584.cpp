//tree, dfs

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

constexpr int MAX = 10000;

int parents[MAX + 1];
int depth[MAX + 1];
int ac[MAX + 1][20];
vector<vector<int> > graph(MAX + 1);

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

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        memset(parents, 0, sizeof(parents));
        memset(depth, 0, sizeof(depth));
        memset(ac, 0, sizeof(ac));
        for (int i = 0; i <= N; ++i) graph[i].clear();

        max_depth = log2(N + 1);

        for (int i = 0; i < N - 1; ++i) {
            int A, B;
            cin >> A >> B;

            graph[A].push_back(B);
            graph[B].push_back(A);

            parents[B] = A;
        }

        int root = 0;
        for (int i = 1; i <= N; ++i) {
            if (parents[i] == 0) {
                root = i;
                break;
            }
        }

        depth[0] = -1;
        dfs(root, 0);

        int x, y;
        cin >> x >> y;

        if (depth[x] != depth[y]) {
            if (depth[x] > depth[y]) swap(x, y);

            for (int i = max_depth; i >= 0; --i) {
                if (depth[x] <= depth[ac[y][i]]) {
                    y = ac[y][i];
                }
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