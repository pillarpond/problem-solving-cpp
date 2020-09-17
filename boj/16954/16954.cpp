//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> tii;

constexpr int MAX = 8;

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool arr[9][MAX][MAX] = {0,};

int bfs() {
    queue<tii> q;
    q.push({0, 7, 0});

    while(!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();

        if (t > 8) return 1;
        if (x == 7 && y == 0) return 1;

        for (int i = 0; i < 9; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if (arr[t][ny][nx] || arr[t + 1][ny][nx]) continue;

            q.push({nx, ny, t + 1});
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c;
            cin >> c;

            if (c == '#') {
                for (int k = i, l = 0; k < 8; ++k, ++l) {
                    arr[l][k][j] = true;
                }
            }
        }
    }

    cout << bfs() << "\n";
    return 0;
}