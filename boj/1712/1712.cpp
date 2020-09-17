//math

#include <iostream>

using namespace std;

int main() {
    auto A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    auto diff = C - B;

    if (diff <= 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << (A / diff) + 1 << endl;
    return 0;
}