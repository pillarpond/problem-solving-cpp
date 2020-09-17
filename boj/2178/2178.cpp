//bfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(vector<vector<int> >& v, int x, int y) {
    point p = {x, y};
    queue<point> q;
    q.push(p);

    while(!q.empty()){
        point curp = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newx = curp.x + dx[i];
            int newy = curp.y + dy[i];

            if (newx >= 0 && newx < v[0].size() && newy >= 0 && newy < v.size()) {
                if (v[newy][newx] == 1) {
                    v[newy][newx] = v[curp.y][curp.x] + 1;
                    point newp = {newx, newy};
                    q.push(newp);
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > visited(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < M; ++j) {
            visited[i][j] = str[j] - '0';
        }
    }

    bfs(visited, 0, 0);
    cout << visited[N - 1][M - 1] << "\n";
    return 0;
}