//bfs

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool check(const vector<vector<vector<int> > > &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            for (int k = 0; k < v[0][0].size(); ++k) {
                if (v[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void aspect(vector<vector<vector<int> > > &v, queue<tuple<int,int,int,int> > &q, tuple<int, int, int, int> t) {
    for (int i = 0; i < 6; ++i) {
        int newx = get<0>(t) + dx[i];
        int newy = get<1>(t) + dy[i];
        int newz = get<2>(t) + dz[i];

        if (newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size() && newz >= 0 && newz < v[0][0].size() && v[newx][newy][newz] == 0) {
            v[newx][newy][newz] = 1;
            q.push(make_tuple(newx, newy, newz, get<3>(t) + 1));
        }
    }
}

int bfs(vector<vector<vector<int> > > &v, queue<tuple<int,int,int,int> > &q) {
    int cnt = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (cnt < get<3>(t)) cnt = get<3>(t);

        aspect(v, q, t);
    }

    if (!check(v)) cnt = -1;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;
    vector<vector<vector<int> > > v(H, vector<vector<int> >(N, vector<int>(M, 0)));
    queue<tuple<int,int,int,int> > q;

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            for (int k = 0; k < v[0][0].size(); ++k) {
                cin >> v[i][j][k];
                if (v[i][j][k] == 1) q.push(make_tuple(i, j, k, 0));
            }
        }
    }

    cout << bfs(v, q) << "\n";
    return 0;
}