//tree, dp

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
vector<vector<int> > cache;
vector<int> w;

int solve(int prev, int node, bool include) {
    int &ret = cache[node][include];
    if (ret != -1) return ret;

    if (include) ret = w[node];
    else ret = 0;

    for (int next : tree[node]) {
        if (prev == next) continue;

        if (include) ret += solve(node, next, false);
        else ret += max(solve(node, next, true), solve(node, next, false));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    tree.resize(N + 1);
    cache.resize(N + 1, vector<int>(2, -1));
    w.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    tree[0].push_back(1);
    cout << solve(-1, 0, false) << "\n";
    return 0;
}