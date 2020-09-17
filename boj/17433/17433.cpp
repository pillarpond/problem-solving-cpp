//math

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int ans = v[1] - v[0];
        for (int i = 1; i < N - 1; ++i) {
            ans = gcd(ans, v[i + 1] - v[i]);
        }

        if (!ans) cout << "INFINITY\n";
        else cout << ans << "\n";
    }

    return 0;
}