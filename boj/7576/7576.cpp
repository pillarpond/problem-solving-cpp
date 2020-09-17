//bfs

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(const vector<vector<int> >& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            if (v[i][j] == 0) return false;
        }
    }
    return true;
}

void aspect(vector<vector<int> >& v, queue<tuple<int, int, int> >& q, tuple<int, int, int> t) {
    for (int i = 0; i < 4; ++i) {
        int newx = get<0>(t) + dx[i];
        int newy = get<1>(t) + dy[i];
        int cnt = get<2>(t) + 1;

        if (newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size() && v[newx][newy] == 0) {
            v[newx][newy] = 1;
            q.push(make_tuple(newx, newy, cnt));
        }
    }
}

int bfs(vector<vector<int> >& v, queue<tuple<int, int, int> >& q) {
    int cnt = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        aspect(v, q, t);
        if (cnt < get<2>(t)) cnt = get<2>(t);
    }

    if (!check(v)) cnt = -1;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int> > v(N, vector<int>(M, 0));
    queue<tuple<int, int, int> > q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 1) q.push(make_tuple(i, j, 0));
        }
    }

    cout << bfs(v, q) << "\n";

    return 0;
}