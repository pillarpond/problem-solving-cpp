//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;

constexpr int MAX = 51;

int arr[MAX][MAX] = {0,};
int day[MAX][MAX] = {0,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C;

bool visited[MAX][MAX] = {0,};

pii S, G;

void bfs1() {
    queue<tii> q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (arr[i][j] == 1) q.push({j, i, 0});
        }
    }

    while(!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (day[ny][nx] != 0) continue;
            if (arr[ny][nx] != 0) continue;

            day[ny][nx] = t + 1;
            q.push({nx, ny, t + 1});
        }
    }
}

string bfs2() {
    queue<tii> q;
    q.push({S.first, S.second, 0});
    visited[S.second][S.first] = true;

    while(!q.empty()) {
        int x, y, d;
        tie(x, y, d) = q.front();
        q.pop();

        if (x == G.first && y == G.second) return to_string(d);

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (visited[ny][nx]) continue;

            if (arr[ny][nx] > 0) continue;
            if (day[ny][nx] > 0 && day[ny][nx] <= d + 1) continue;
            
            visited[ny][nx] = true;
            q.push({nx, ny, d + 1});
        }
    }
    return "KAKTUS";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c;
            cin >> c;

            switch (c) {
                case 'S':
                    S = {j, i};
                    break;
                case 'D':
                    G = {j, i};
                    arr[i][j] = -1;
                    break;
                case '*':
                    arr[i][j] = 1;
                    break;
                case 'X':
                    arr[i][j] = 2;
                    break;
            }
        }
    }

    bfs1();
    cout << bfs2() << "\n";

    return 0;
}