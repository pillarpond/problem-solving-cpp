//tree, dp

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
vector<vector<int> > cache;

int solve(int prev, int node, bool include) {
    int &ret = cache[node][include];
    if (ret != -1) return ret;

    ret = include;
    for (int next : tree[node]) {
        if (next == prev) continue;
        if (include) ret += min(solve(node, next, false), solve(node, next, true));
        else ret += solve(node, next, true);
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

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << min(solve(0, 1, false), solve(0, 1, true)) << "\n";

    return 0;
}