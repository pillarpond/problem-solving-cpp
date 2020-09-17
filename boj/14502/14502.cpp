//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

constexpr int MAX = 8;

int arr[MAX][MAX] = {1,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;
int res = 987654321;

int bfs() {
    queue<pii> q;

    int cnt = 0;
    int tmp[MAX][MAX];

    memcpy(tmp, arr, sizeof(tmp));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tmp[i][j] == 2) {
                q.push({j, i});
                ++cnt;
            }
        }
    }

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (tmp[ny][nx] == 0) {
                tmp[ny][nx] = 2;
                q.push({nx, ny});
                ++cnt;
            }
        }
    }

    return cnt;
}

void dfs(int x, int y, int cnt) {
    if (cnt == 3) {
        res = min(res, bfs());
        return;
    }

    if (y == N) return;
    if (x == M) return dfs(0, y + 1, cnt);

    if (arr[y][x] == 0) {
        arr[y][x] = 1;
        dfs(x + 1, y, cnt + 1);
        arr[y][x] = 0;
    } 

    dfs(x + 1, y, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int wall = 3;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) ++wall;
        }
    }

    dfs(0, 0, 0);
    cout << N * M - res - wall << "\n";
    return 0;
}