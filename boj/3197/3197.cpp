//bfs, bsearch

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;

constexpr int MAX = 1501;

pii L1 = {-1, -1}, L2;

int R, C;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int arr[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};

int bfs2(int day) {
    int sx, sy;
    tie(sx, sy) = L1;

    queue<pii> q;
    q.push({sx, sy});

    memset(visited, 0, sizeof(visited));
    visited[sx][sy] = true;

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (x == L2.first && y == L2.second) return 1;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] > day) continue;

            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }

    return 0;
}

void bfs1() {
    queue<tii> q;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!arr[i][j]) {
                q.push({j, i, 0});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        int x, y, c;
        tie(x, y, c) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] != -1) continue;

            visited[ny][nx] = true;
            arr[ny][nx] = c + 1;
            q.push({nx, ny, c + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c;
            cin >> c;

            if (c == 'X') arr[i][j] = -1;
            if (c == 'L') {
                if (L1.first == -1) L1 = {j, i};
                else L2 = {j, i};
            }
        }
    }

    bfs1();
    int left = 0, right = max(R, C);
    int result = MAX;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (bfs2(mid)) {
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}