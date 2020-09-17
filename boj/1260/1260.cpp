//dfs, bfs

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int N, M, V;

void dfs(const vector<vector<bool> >& g) {
    bool visited[g.size()];
    memset(visited, false, sizeof(visited));
    stack<int> s;

    s.push(V);
    visited[V] = true;
    cout << V << " ";

    do {
        int num = s.top();
        s.pop();

        for (int i = 1; i <= N; ++i) {
            if (g[num][i] && !visited[i]) {
                cout << i << " ";
                visited[i] = true;

                s.push(num);
                s.push(i);
                break;
            }
        }
    } while(!s.empty());
    cout << "\n";
}


void bfs(const vector<vector<bool> >& g) {
    bool visited[g.size()];
    memset(visited, false, sizeof(visited));
    queue<int> q;

    q.push(V);
    visited[V] = true;

    do {
        int num = q.front();
        cout << num << " ";
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (g[num][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    } while(!q.empty());
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;
    vector<vector<bool> > g(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = true;
    }

    dfs(g);
    bfs(g);
    return 0;
}