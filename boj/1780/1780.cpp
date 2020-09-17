//dnc

#include <iostream>

using namespace std;

int arr[2188][2188] = {0};

int check(int r, int c, int l) {
    int v = arr[r][c];
    for (int i = r; i < r + l; ++i) {
        for (int j = c; j < c + l; ++j) {
            if (v != arr[i][j]) return -2;
        }
    }
    return v;
}

void solve(int r, int c, int l, int& o, int& z, int& ne) {
    int res = check(r, c, l);
    if (res < -1) {
        int tw = l / 3, th = l * 2 / 3;

        solve(r, c, tw, o, z, ne);
        solve(r + tw, c, tw, o, z, ne);
        solve(r + th, c, tw, o, z, ne);

        solve(r, c + tw, tw, o, z, ne);
        solve(r + tw, c + tw, tw, o, z, ne);
        solve(r + th, c + tw, tw, o, z, ne);

        solve(r, c + th, tw, o, z, ne);
        solve(r + tw, c + th, tw, o, z, ne);
        solve(r + th, c + th, tw, o, z, ne);
        return;
    } else if (res == 0) {
        z++;
    } else if (res == -1) {
        ne++;
    } else {
        o++;
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

    int o = 0, z = 0, ne = 0;
    solve(1, 1, N, o, z, ne);

    cout << ne << "\n";
    cout << z << "\n";
    cout << o << "\n";

    return 0;
}