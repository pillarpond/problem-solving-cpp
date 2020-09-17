//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 15;

bool grid[MAX][MAX] = {0,};

int N;

bool check(int x, int y) {
    for (int i = 0; i < x; ++i) {
        if (grid[y][i]) return false;
    }

    for (int i = x - 1, j = y - 1; j >= 0; --i, --j) {
        if (grid[j][i]) return false;
    }

    for (int i = x - 1, j = y + 1; j < N; --i,  ++j) {
        if (grid[j][i]) return false;
    }

    return true;
}

int dfs(int cnt) {
    if (cnt == N) return 1;

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        if (!grid[i][cnt] && check(cnt, i)) {
            grid[i][cnt] = true;
            ans += dfs(cnt + 1);
            grid[i][cnt] = false;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cout << dfs(0) << "\n";
    return 0;
}