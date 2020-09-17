//tsort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parents;
vector<int> visited;
vector<vector<int> > g;

int find(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int cycle(int here) {
    if (visited[here]) {
        if (visited[here] == -1) return true;
        return false;
    }

    visited[here] = -1;
    for(int next : g[here]) {
        if (cycle(next)) return true;
    }
    visited[here] = 1;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int,int> > vec;
    parents.resize(N + 1);
    for (int i = 0; i <= N; ++i) parents[i] = i;

    for (int i = 0; i < M; ++i) {
        int u, v;
        char equal;

        cin >> u >> equal >> v;

        if (equal == '=') {
            unite(u, v);
        } else {
            vec.push_back({u, v});
        }
    }

    g.resize(N + 1);
    visited.resize(N + 1, 0);

    for (auto p : vec) {
        int u = find(p.first);
        int v = find(p.second);

        g[u].push_back(v);
    }

    for (int i = 1; i <= N; ++i) {
        if (cycle(i)) {
            cout << "inconsistent\n";
            return 0;
        }
    }
    cout << "consistent\n";
    return 0;
}