//tree, dfs

#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<vector<int> > &tree, vector<int> &cache, vector<bool> &visited, int node) {
    int &res = cache[node];
    if (res != 0) return res;

    res = 1;
    for(int child : tree[node]) {
        if (!visited[child]) {
            visited[child] = true;
            res += solve(tree, cache, visited, child);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;

    vector<vector<int> > tree(N + 1);
    vector<bool> visited(N + 1, false);
    vector<int> cache(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;

        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    visited[R] = true;
    solve(tree, cache, visited, R);

    for (int i = 0; i < Q; ++i) {
        int query;
        cin >> query;
        cout << solve(tree, cache, visited, query) << "\n";
    }

    return 0;
}