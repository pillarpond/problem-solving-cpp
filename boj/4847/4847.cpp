//math

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 257;

int N;

int s[MAX] = {0,};
int d[MAX] = {0,};
int a[MAX] = {0,};

void solve() {
    if (N == 1) {
        a[1] = s[1];
        return;
    }

    for (int i = 1; i < N; i *= 2) {
        for (int j = 1; j <= i; ++j) {
            a[2 * j - 1] = (s[j] + d[j]) / 2;
            a[2 * j] = (s[j] - d[j]) / 2;
        }

        for (int j = 1; j <= i * 2; ++j) {
            s[j] = a[j];
        }

        for (int j = 1; j + i <= N; ++j) {
            d[j] = d[j + i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        cin >> N;
        if (!N) break;

        memset(a, 0, sizeof(s));
        memset(a, 0, sizeof(d));
        memset(a, 0, sizeof(a));

        cin >> s[1];

        for (int i = 1; i <= N - 1; ++i) {
            cin >> d[i];
        }

        solve();

        for (int i = 1; i <= N; ++i) {
            cout << a[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}