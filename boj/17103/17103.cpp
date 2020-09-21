//sieve

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 1000001;

bool prime[MAX];

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        for (int j = i + i; j < MAX; j += i) {
            prime[j] = false;
        }
    }
}

int goldbach(int n) {
    if (n == 4) return 1;

    int ret = 0;

    for (int i = 3; i <= n / 2; i += 2) {
        if (!prime[i]) continue;
        if (!prime[n - i]) continue;

        ++ret;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    sieve();

    while(T--) {
        int N;
        cin >> N;

        cout << goldbach(N) << "\n";
    }
    return 0;
}