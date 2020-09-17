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

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int> > g(n + 1);
        vector<int> order(n + 1);
        vector<int> cnt(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> order[i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                g[order[i]].push_back(order[j]);
                ++cnt[order[j]];
            }
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            bool change = false;
            for (auto iter = g[a].begin(); iter != g[a].end(); ++iter) {
                if (*iter == b) {
                    g[a].erase(iter);
                    g[b].push_back(a);
                    ++cnt[a];
                    --cnt[b];
                    change = true;
                    break;
                }
            }

            if (!change) {
                for (auto iter = g[b].begin(); iter != g[b].end(); ++iter) {
                    if (*iter == a) {
                        g[b].erase(iter);
                        g[a].push_back(b);
                        ++cnt[b];
                        --cnt[a];
                        break;
                    }
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) q.push(i);
        }

        bool certain = true;
        vector<int> ans;

        while(!q.empty()) {
            if (q.size() > 1) {
                certain = false;
                break;
            }
            int v = q.front();
            q.pop();
            ans.push_back(v);

            for (int u : g[v]) {
                --cnt[u];
                if (cnt[u] == 0) q.push(u);
            }
        }

        if (!certain) {
            cout << "?\n";
        } else if (ans.size() != n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int a : ans) cout << a << " ";
            cout << "\n";
        }
    }
    return 0;
}