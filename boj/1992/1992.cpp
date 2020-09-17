//dnc

#include <iostream>

using namespace std;

int arr[65][65] = {0};

int check(int r, int c, int l) {
    int v = arr[r][c];
    for (int i = r; i < r + l; ++i) {
        for (int j = c; j < c + l; ++j) {
            if (v != arr[i][j]) return -1;
        }
    }
    return v;
}

void solve(int r, int c, int l) {
    int res = check(r, c, l);
    if (res < 0) {
        cout << "(";
        solve(r, c, l / 2);
        solve(r, c + l / 2, l / 2);
        solve(r + l / 2, c, l / 2);
        solve(r + l / 2, c + l / 2, l / 2);
        cout << ")";
        return;
    } else {
        cout << res;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    auto N = 0;
    cin >> N;

    string line;
    for (int i = 1; i <= N; ++i) {
        cin >> line;
        for (int j = 1; j <= N; ++j) {
            arr[i][j] = line[j - 1] - '0';
        }
    }

    solve(1, 1, N);
    cout << "\n";

    return 0;
}