//dfs

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

void dfs(vector<vector<bool> >& v, int x, int y) {
    v[y][x] = false;
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
                if (v[newy][newx]) {
                    v[newy][newx] = false;
                    point newp = {newx, newy};
                    q.push(newp);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<bool> > v(M, vector<bool>(N, false));
        
        while (K--) {
            int x, y;
            cin >> y >> x;
            v[y][x] = true;
        }

        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (v[i][j]) {
                    ++cnt;
                    dfs(v, j, i);
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}