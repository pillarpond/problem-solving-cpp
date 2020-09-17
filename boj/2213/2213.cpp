//tree, dp

#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> w;

vector<vector<int> > cache;
vector<vector<int> > tree;

int solve(int prev, int node, bool include) {
    int &res = cache[node][include];
    if (res != -1) return res;

    if (include) res = w[node];
    else res = 0;

    for (int next : tree[node]) {
        if (prev == next) continue;

        if (include) {
            res += solve(node, next, false);
        } else {
            int t1 = solve(node, next, false);
            int t2 = solve(node, next, true);
            res += max(t1, t2);
        }
    }

    return res;
}

void check(int prev, int node, bool include) {
    if (include) visited[node] = true;

    for (int next : tree[node]) {
        if (prev == next) continue;

        if (!include && cache[next][1] > cache[next][0]) check(node, next, true);
        else check(node, next, false);
    }
}

int main() {
    int n;
    cin >> n;

    w.resize(n + 1, 0);
    visited.resize(n + 1, false);
    cache.resize(n + 1, vector<int>(2, -1));
    tree.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;

        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    tree[0].push_back(1);
    cout << solve(-1, 0, false) << "\n";
    check(-1, 0, false);

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}