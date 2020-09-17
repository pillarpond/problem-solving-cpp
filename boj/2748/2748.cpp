//dp

#include <iostream>
using namespace std;

unsigned long fibo[91] = {0};

int main() {
    auto n = 0;
    cin >> n;

    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cout << fibo[n] << endl;
    return 0;
}