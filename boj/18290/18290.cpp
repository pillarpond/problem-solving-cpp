//bfs

#include <iostream>

using namespace std;

constexpr int MAX = 11;

int N, M, K;
int arr[MAX][MAX] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool visited[MAX][MAX] = {0,};

bool check(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (visited[ny][nx]) return false;
    }

    return true;
}

int bfs(int x, int y, int c) {
    if (c == K) return 0;
    if (y == N) return -987654321;
    if (x == M) return bfs(0, y + 1, c);

    int ret = -987654321;

    if (check(x, y)) {
        visited[y][x] = true;
        ret = bfs(x + 1, y, c + 1) + arr[y][x];
        visited[y][x] = false;
    }

    ret = max(ret, bfs(x + 1, y, c));

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << bfs(0, 0, 0) << "\n";
    return 0;
}