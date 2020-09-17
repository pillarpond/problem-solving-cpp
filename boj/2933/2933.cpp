//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

constexpr int MAX = 101;
typedef pair<int,int> pii;

int R, C;
int N;

int arr[MAX][MAX] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 , 1};

bool visited[MAX][MAX] = {0,};

vector<pii> cluster;

int bfs(int sx, int sy) {
    if (sx == C || sx < 0 || sy == R || sy < 0) return true;
    if (!arr[sy][sx]) return true;
    
    bool land = false;

    queue<pii> q;
    q.push({sx, sy});

    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = true;

    cluster.clear();
    cluster.push_back({sx, sy});

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == C || nx < 0 || ny < 0) continue;
            if (ny == R) {
                land = true;
                continue;
            }
            if (visited[ny][nx]) continue;
            if (!arr[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({nx, ny});
            cluster.push_back({nx, ny});
        }
    }

    return land;
}

void fall(int x, int y) {
    arr[y][x] = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (bfs(nx, ny)) continue;

        int cnt = R;
        for (pii c : cluster) arr[c.second][c.first] = 0;

        for (pii c : cluster) {
            int next = c.second + 1;
            for (int i = 0; i < R; ++i) {
                if (next == R || arr[next][c.first]) {
                    cnt = min(cnt, i);
                    break;
                }
                ++next;
            }
        }

        for (pii c : cluster) {
            arr[c.second + cnt][c.first] = 1;
        }
    }
}

void print() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (arr[i][j]) cout << "x";
            else cout << ".";
        }
        cout << "\n";
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

            if (c == 'x') arr[i][j] = 1;
        }
    }

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;

        if (i % 2) {
            for (int j = C - 1; j >= 0; --j) {
                if (arr[R - h][j] == 1) {
                    fall(j, R - h);
                    break;
                }
            }
        } else {
            for (int j = 0; j < C; ++j) {
                if (arr[R - h][j] == 1) {
                    fall(j, R - h);
                    break;
                }
            }
        }
        //cout << "\n";
        //print();
    }

    print();

    return 0;
}