//math

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX = 2000001;

bool prime[MAX];

vector<int> v;

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        for (int j = i + i; j < MAX; j += i) {
            prime[j] = false;
        }
    }

    for (int i = 2; i < MAX; ++i) {
        if (prime[i]) v.push_back(i);
    }
}

bool partner(long long n) {
    if (n < 4) return false;
    if (n % 2 == 0) return true;

    n -= 2;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] * v[i] > n) break;
        if (n % v[i] == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    sieve();

    while(T--) {
        long long A, B;
        cin >> A >> B;

        if (partner(A + B)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}