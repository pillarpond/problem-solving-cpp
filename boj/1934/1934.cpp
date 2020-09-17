//math

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int icm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int A, B;
        cin >> A >> B;

        cout << icm(A, B) << "\n";
    }

    return 0;
}