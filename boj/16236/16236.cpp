//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
typedef tuple<int,int,int> tii;

constexpr int MAX = 21;

int arr[MAX][MAX] = {0,};
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

int N;
int sx, sy;
int eat = 0, size = 2;
int cnt = 0;

bool visited[MAX][MAX] = {0,};

int bfs() {
    queue<tii> q;
    q.push({sx, sy, 0});

    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = true;

    priority_queue<tii> pq;

    while(!q.empty()) {
        int x, y, c;
        tie(x, y, c) = q.front();
        q.pop();

        if (arr[y][x] > 0 && arr[y][x] < size) {
            pq.push({-c, -y, -x});
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] > size) continue;

            visited[ny][nx] = true;
            q.push({nx, ny, c + 1});
        }
    }

    if (!pq.empty()) {
        int x, y, c;
        tie(c, y, x) = pq.top();

        sx = -x;
        sy = -y;

        arr[sy][sx] = 0;
        ++eat;

        if (eat == size) {
            eat = 0;
            ++size;
        }

        return -c;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                arr[i][j] = 0;
                sx = j;
                sy = i;
            }
        }
    }

    int res;
    do {
        res = bfs();
        cnt += res;
    } while(res);

    cout << cnt << "\n";
    return 0;
}