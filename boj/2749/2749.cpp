//dp

#include <iostream>

using namespace std;

const int MOD = 1000000;
int fibo[1500001] = {0};


int main() {
    long long n;
    cin >> n;

    fibo[1] = 1;
    for (int i = 2; i <= 1500000; ++i) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    }

    cout << fibo[n % 1500000] << endl;

    return 0;
}