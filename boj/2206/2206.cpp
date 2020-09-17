//bfs

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

constexpr int MAX = 1000;

bool visited[MAX+1][MAX+1][2] = {0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<string> &v, queue<tuple<int,int,int,int> > &q) {
    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        int x = get<0>(t);
        int y = get<1>(t);
        int cnt = get<2>(t);
        int broken = get<3>(t);
        if (x == v.size() - 1 && y == v[0].size() - 1) return cnt;

        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size()) {
                if (v[newx][newy] == '0' && !visited[newx][newy][broken]) {
                    visited[newx][newy][broken] = true;
                    q.push(make_tuple(newx, newy, cnt+1, broken));
                } else if (v[newx][newy] == '1' && broken == 0 && !visited[newx][newy][1]) {
                    visited[newx][newy][1] = true;
                    q.push(make_tuple(newx, newy, cnt+1, 1));
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    queue<tuple<int,int,int,int> > q;
    q.push(make_tuple(0,0,1,0));

    cout << bfs(v, q) << "\n";

    return 0;
}