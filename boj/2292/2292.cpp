//math

#include <iostream>

using namespace std;

int main() {
    auto N = 0, cnt = 0;
    cin >> N;

    auto line = 1;

    while (N > 0) {
        ++cnt;
        N -= line;
        line = 6 * cnt;
    }
    cout << cnt << endl;
    return 0;
}