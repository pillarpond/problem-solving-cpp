//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int,int> tii;

constexpr int MAX = 101;

int arr[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int W, H;

int visited[MAX][MAX] = {-1,};

pii c1 = {-1, -1}, c2 = {-1, -1};

int bfs() {
    queue<tii> q;
    q.push({c1.first, c1.second, 0, -1});
    visited[c1.second][c1.first] = 0;

    int res = 987654321;

    while(!q.empty()) {
        int x, y, c, d;
        tie(x, y, c, d) = q.front();
        q.pop();

        if (x == c2.first && y == c2.second) {
            res = min(res, c);
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (visited[ny][nx] != -1 && visited[ny][nx] < c) continue;
            if (arr[ny][nx] == 1) continue;

            visited[ny][nx] = c;

            if (d == -1 || d == i) q.push({nx, ny, c, i});
            else q.push({nx, ny, c + 1, i});
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> H;

    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;

            switch (c)
            {
            case '*':
                arr[i][j] = 1;
                break;
            case 'C':
                if (c1.first == -1) c1 = {j, i};
                else c2 = {j, i};
                break;
            }
        }
    }

    cout << bfs() << "\n";
    return 0;
}