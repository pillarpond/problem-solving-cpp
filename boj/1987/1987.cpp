//dfs

#include <iostream>

using namespace std;

constexpr int MAX = 21;

int arr[MAX][MAX] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C;
int res = 0;

bool visited[26] = {0,};

void dfs(int x, int y, int cnt) {
    res = max(res, cnt);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if (!visited[arr[ny][nx]]) {
            visited[arr[ny][nx]] = true;
            dfs(nx, ny, cnt + 1);
            visited[arr[ny][nx]] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j){
            arr[i][j] = str[j] - 'A';
        }
    }

    visited[arr[0][0]] = true;
    dfs(0, 0, 1);

    cout << res << "\n";
    return 0;
}