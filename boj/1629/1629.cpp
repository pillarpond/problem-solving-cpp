//math

#include <iostream>

using namespace std;

int A, B, C;

long long power(int a, int b) {
    if (b == 0) return 1;

    long long tmp = power(a, b/2);
    long long res = (tmp * tmp) % C;

    if (b % 2) return (res * a) % C;
    return res;
}

int main() {
    cin >> A >> B >> C;

    cout << power(A, B) << "\n";
    return 0;
}