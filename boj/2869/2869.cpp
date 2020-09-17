//math

#include <iostream>

using namespace std;

int main() {
    auto A = 0, B = 0, V = 0;
    cin >> A >> B >> V;

    V -= A;
    if (V <= 0) {
        cout << 1 << endl;
        return 0;
    }

    auto res = (V / (A - B)) + 1;
    if (V % (A - B)) {
        res++;
    }

    cout << res << endl;
    return 0;
}