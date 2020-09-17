//lca

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 100001;
constexpr int INF = 987654321;

int max_dp[MAX][20] = {0,};
int min_dp[MAX][20] = {0,};

int ac[MAX][20] = {0,};
int depth[MAX] = {0,};
vector<vector<pair<int,int> > > graph;

int N;
int max_depth;

void dfs(int node, int parent, int val) {
    depth[node] = depth[parent] + 1;
    ac[node][0] = parent;
    max_dp[node][0] = val;
    min_dp[node][0] = val;

    for (int i = 1; i <= max_depth; ++i) {
        int a = ac[node][i - 1];
        ac[node][i] = ac[a][i - 1];
    }

    for (auto p : graph[node]) {
        if (p.first != parent) dfs(p.first, node, p.second);
    }
}

void dp() {
    for (int i = 1; i <= max_depth; ++i) {
        for (int j = 1; j <= N; ++j) {
            int a = ac[j][i - 1];
            min_dp[j][i] = min(min_dp[a][i - 1], min_dp[j][i - 1]);
            max_dp[j][i] = max(max_dp[a][i - 1], max_dp[j][i - 1]);
        }
    }
}

pair<int, int> lca(int x, int y) {
    int rmin = INF;
    int rmax = -INF;

    if (depth[x] > depth[y]) swap(x, y);
    for (int i = max_depth; i >= 0; --i) {
        if (depth[y] - depth[x] >= (1 << i)) {
            rmin = min(rmin, min_dp[y][i]);
            rmax = max(rmax, max_dp[y][i]);
            y = ac[y][i];
        }
    }
    if (x == y) return{rmin, rmax};
    for (int i = max_depth; i >= 0; --i) {
        if (ac[x][i] != ac[y][i]) {
            rmin = min(rmin, min(min_dp[x][i], min_dp[y][i]));
            rmax = max(rmax, max(max_dp[x][i], max_dp[y][i]));
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    rmin = min(rmin, min(min_dp[x][0], min_dp[y][0]));
    rmax = max(rmax, max(max_dp[x][0], max_dp[y][0]));
    return {rmin, rmax};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    graph.resize(N + 1);
    max_depth = log2(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    depth[0] = -1;
    dfs(1, 0, 0);
    dp();

    int K;
    cin >> K;

    while(K--) {
        int D, E;
        cin >> D >> E;

        auto p = lca(D, E);
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}