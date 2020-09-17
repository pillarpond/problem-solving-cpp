//sieve

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 1000000;

bool prime[MAX] = {0,};

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < 1000000; ++i) {
        for (int j = i + i; j < 1000000; j += i) {
            prime[j] = false;
        }
    }
}

void goldbach(int n) {
    for (int i = 3; i < n; i += 2) {
        if (!prime[i]) continue;
        if (!prime[n - i]) continue;

        cout << n << " = " << i << " + " << n - i << "\n";
        return; 
    }

    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    while(1) {
        int n;
        cin >> n;

        if (n == 0) break;
        goldbach(n);
    }

    return 0;
}