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
    vector<int> cnt(N + 1);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;

        g[A].push_back(B);
        ++cnt[B];
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= N; ++i) {
        if (cnt[i] == 0) pq.push(i);
    }

    vector<int> ans;
    while(!pq.empty()) {
        int v = pq.top();
        pq.pop();
        ans.push_back(v);

        for (int u : g[v]) {
            --cnt[u];
            if (cnt[u] == 0) pq.push(u);
        }
    }

    for (int a : ans) cout << a << " ";
    cout << "\n";

    return 0;
}