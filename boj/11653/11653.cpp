//math

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto N = 0;
    cin >> N;

    while (N > 1) {
        for (int i = 2; i <= N; ++i) {
            if (N % i == 0) {
                cout << i << "\n";
                N /= i;
                break;
            }
        }
    }

    return 0;
}