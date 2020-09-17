//scc

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAX = 10001;

int visited[MAX] = {0,};
int cnt = 0;

vector<vector<int> > graph;
vector<vector<int> > rgraph;
vector<vector<int> > ans;

stack<int> s;

void dfs(int now) {
    visited[now] = true;

    for (int next : graph[now]) {
        if (!visited[next]) dfs(next);
    }
    s.push(now);
}

void scc(int now) {
    visited[now] = true;
    ans[cnt].push_back(now);

    for (int next : rgraph[now]) {
        if (!visited[next]) scc(next);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    graph.resize(V + 1);
    rgraph.resize(V + 1);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) dfs(i);
    }

    memset(visited, 0, sizeof(visited));

    while(!s.empty()) {
        int top = s.top();
        s.pop();

        if (visited[top]) continue;
        
        ans.push_back(vector<int>());
        scc(top);
        cnt++;
    }

    for (auto &vec : ans) sort(vec.begin(), vec.end());
    sort(ans.begin(), ans.end(), [](const vector<int> &v1, const vector<int> &v2){return v1[0] < v2[0];});

    cout << ans.size() << "\n";
    for (auto &vec : ans) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "-1\n";
    }

    return 0;
}