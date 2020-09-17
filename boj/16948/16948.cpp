//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;

constexpr int MAX = 201;

int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, 1, -2, 2, -1, 1};

int N;

bool visited[MAX][MAX] = {0,};

pii start, goal;

int bfs() {
    queue<tii> q;
    q.push({start.first, start.second, 0});

    while(!q.empty()) {
        int r, c, cnt;
        tie(r, c, cnt) = q.front();
        q.pop();

        if (r == goal.first && c == goal.second) return cnt;

        for (int i = 0; i < 6; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> start.first >> start.second >> goal.first >> goal.second;
    cout << bfs() << "\n";

    return 0;
}