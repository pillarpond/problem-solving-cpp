//dfs

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int> > g(n);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        g[s-1].push_back(e-1);
        g[e-1].push_back(s-1);
    }

    bool visited[n];
    memset(visited, false, sizeof(visited));

    stack<int> s;
    s.push(0);
    visited[0] = true;
    int cnt = 0;

    while(!s.empty()) {
        int num = s.top();
        s.pop();

        for (int i = 0; i < g[num].size(); ++i) {
            if (!visited[g[num][i]]) {
                visited[g[num][i]] = true;
                cnt++;
                s.push(num);
                s.push(g[num][i]);
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}