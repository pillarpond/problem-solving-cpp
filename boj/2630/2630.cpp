//dnc

#include <iostream>

using namespace std;

int arr[129][129] = {0};

int check(int r, int c, int l) {
    int v = arr[r][c];
    for (int i = r; i < r + l; ++i) {
        for (int j = c; j < c + l; ++j) {
            if (v != arr[i][j]) return -1;
        }
    }
    return v;
}

void solve(int r, int c, int l, int& w, int& b) {
    int res = check(r, c, l);
    if (res < 0) {
        solve(r, c, l / 2, w, b);
        solve(r + l / 2, c, l / 2, w, b);
        solve(r, c + l / 2, l / 2, w, b);
        solve(r + l / 2, c + l / 2, l / 2, w, b);
        return;
    } else if (res == 0) {
        w++;
    } else {
        b++;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    auto N = 0;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
        }
    }

    int w = 0, b = 0;
    solve(1, 1, N, w, b);

    cout << w << "\n";
    cout << b << "\n";

    return 0;
}