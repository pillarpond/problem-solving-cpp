//bfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void find(const vector<vector<int> > &g, vector<int> &parents) {
    vector<bool> visited(g.size(), false);
    visited[1] = true;

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int cand : g[parent]) {
            if (!visited[cand]) {
                visited[cand] = true;
                parents[cand] = parent;
                q.push(cand);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int> > g(N + 1);
    vector<int> parents(N + 1, -1);

    while(--N) {
        int p1, p2;
        cin >> p1 >> p2;

        g[p1].push_back(p2);
        g[p2].push_back(p1);
    }

    find(g, parents);

    for (int i = 2; i < parents.size(); ++i) cout << parents[i] << "\n";
}