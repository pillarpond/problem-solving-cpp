//sieve

#include <iostream>
#include <cmath>

using namespace std;

bool arr[1000001] = {0};

int main() {
    arr[0] = arr[1] = true;
    for (int i = 2; i <= sqrt(1000000); ++i) {
        if (arr[i] == false) {
            for (int j = i; i * j <= 1000000; ++j) {
                arr[i * j] = true;
            }
        }
    }

    auto M = 0, N = 0;
    cin >> M >> N;

    for (int i = M; i <= N; ++i) {
        if (arr[i] == false) {
            cout << i << "\n";
        }
    }
    return 0;
}