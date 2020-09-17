//bfs

#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;

constexpr int MAX = 101;

int N;
int arr[MAX][MAX] = {0,};
int cbarr[MAX][MAX] = {0,};
int group[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int sx, int sy, int idx, bool blind) {
    queue<pii> q;
    q.push({sx, sy});
    group[sy][sx] = idx;

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (group[ny][nx] != 0) continue;
            if (blind && (cbarr[y][x] != cbarr[ny][nx])) continue;
            if (!blind && (arr[y][x] != arr[ny][nx])) continue;

            group[ny][nx] = idx;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;

            switch (c)
            {
            case 'R':
                cbarr[i][j] = arr[i][j] = 1;
                break;
            case 'G':
                cbarr[i][j] = 1;
                arr[i][j] = 2;
                break;
            default:
                arr[i][j] = 0;
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (group[i][j] == 0) bfs(j, i, ++cnt, false);
        }
    }

    cout << cnt << " ";

    cnt = 0;
    memset(group, 0, sizeof(group));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (group[i][j] == 0) bfs(j, i, ++cnt, true);
        }
    }

    cout << cnt << "\n";

    return 0;
}