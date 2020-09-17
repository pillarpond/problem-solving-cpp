//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int,int,int,int> tii;

constexpr int MAX = 1001;

int arr[MAX][MAX] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, K;

bool visited[11][MAX][MAX] = {0,};

int bfs() {
    queue<tii> q;
    q.push({0, 0, 0, 1});
    visited[0][0][0] = true;

    while(!q.empty()) {
        int x, y, wall, cnt;
        tie(x, y, wall, cnt) = q.front();
        q.pop();

        if (x == M - 1 && y == N - 1) return cnt;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (visited[wall][ny][nx]) continue;

            if (arr[ny][nx] == 0) {
                visited[wall][ny][nx] = true;
                q.push({nx, ny, wall, cnt + 1});
            } else if (wall < K) {
                visited[wall][ny][nx] = true;
                q.push({nx, ny, wall + 1, cnt + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    cout << bfs() << "\n";
    return 0;
}