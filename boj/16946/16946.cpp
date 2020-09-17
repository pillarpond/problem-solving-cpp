//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
typedef pair<int,int> pii;

constexpr int MAX = 1001;

int arr[MAX][MAX] = {0,};
int group[MAX][MAX] = {0,};

int ans[MAX][MAX] = {0,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;

int bfs(pii p, int num) {
    queue<pii> q;
    q.push(p);

    int cnt = 1;
    group[p.second][p.first] = num;

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (group[ny][nx] != 0) continue;

            if (arr[ny][nx] == 0) {
                group[ny][nx] = num;
                q.push({nx, ny});
                ++cnt;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;

            arr[i][j] = c - '0';
        }
    }

    int num = 1;
    vector<int> v;
    v.push_back(0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 0 && group[i][j] == 0) v.push_back(bfs({j, i}, num++));
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 1) {
                set<int> s;
                for (int k = 0; k < 4; ++ k) {
                    int x = j + dx[k];
                    int y = i + dy[k];

                    if (x < 0 || x >= M || y < 0 || y >= N) continue;
                    s.insert(group[y][x]);
                }

                int sum = 1;
                for (int e : s) sum += v[e];
                cout << sum % 10;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }

    return 0;
}