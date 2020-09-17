//dfs

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[25][25] = {false,};
string arr[25];

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; ++i) {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx >= 0 && newx < N && newy >= 0 && newy < N && !visited[newx][newy] && arr[newx][newy] == '1')
            dfs(newx, newy);
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == '1' && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << "\n";

    return 0;
}