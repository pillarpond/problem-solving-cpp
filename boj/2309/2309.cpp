//brute force

#include <iostream>
#include <algorithm>

using namespace std;

int dwarfs[9];
int x, y;
int sum = 0;

void solve() {
    for (x = 0; x < 8; ++x) {
        for (y = x + 1; y < 9; ++y) {
            if (sum - dwarfs[x] - dwarfs[y] == 100) return; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; ++i) {
        cin >> dwarfs[i];
        sum += dwarfs[i];
    }

    sort(dwarfs, dwarfs + 9);
    solve();

    for (int i = 0; i < 9; ++i) {
        if (i == x || i == y) continue;
        cout << dwarfs[i] << "\n";
    }

    return 0;
}