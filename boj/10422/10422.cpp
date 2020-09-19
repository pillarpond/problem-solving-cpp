//dp

#include <iostream>

using namespace std;

constexpr int MOD = 1000000007;
constexpr int MAX = 5001;

long long cache[MAX] = {0,};

long long count(int n) {
    long long &ret = cache[n];
    if (ret != 0) return ret;
    if (n == 0) return ret = 1;

    for (int i = 2; i <= n; i += 2) {
        ret += count(i - 2) * count(n - i);
        ret %= MOD;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int L;
        cin >> L;

        if (L % 2) {
            cout << "0\n";
            continue;
        }

        cout << count(L) << "\n";
    }

    return 0;
}