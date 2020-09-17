//tsort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > g(N + 1);
    vector<int> count(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;

        g[A].push_back(B);
        ++count[B];
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (count[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : g[v]) {
            --count[u];
            if (count[u] == 0) q.push(u);
        }
    }
    cout << "\n";

    return 0;
}