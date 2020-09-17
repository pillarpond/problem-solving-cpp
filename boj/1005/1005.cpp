//tsort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N, K;
        cin >> N >> K;

        vector<int> D(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> D[i];
        }

        vector<vector<int> > g(N + 1);
        vector<int> cnt(N + 1);

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;

            g[X].push_back(Y);
            ++cnt[Y];
        }

        int W;
        cin >> W;

        queue<int> q;
        vector<int> cache(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            if (cnt[i] == 0) {
                q.push(i);
                cache[i] = D[i];
            }
        }

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : g[v]) {
                --cnt[u];
                cache[u] = max(cache[v] + D[u], cache[u]);
                if (cnt[u] == 0) {
                    q.push(u);
                }
            }
        }

        cout << cache[W] << "\n";
    }

    return 0;
}