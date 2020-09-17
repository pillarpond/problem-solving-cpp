//dp

#include <iostream>
using namespace std;

const static int MOD = 15746; 
unsigned long num[1000001] = {0};

int main() {
    auto N = 0;
    cin >> N;

    num[1] = 1;
    num[2] = 2;
    for (int i = 3; i <= N; i++) {
        num[i] = ((num[i - 1] % MOD) + (num[i - 2] % MOD)) % MOD;
    }

    cout << num[N] << endl;
    return 0;
}