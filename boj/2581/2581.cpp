//sieve

#include <iostream>

using namespace std;

int arr[10001] = {0};

int main() {
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= 10000; ++i) {
        if (arr[i] == 0) {
            for (int j = i; i * j <= 10000; ++j) {
                arr[i * j] = 1;
            }
        }
    }

    auto M = 0, N = 0;
    cin >> M >> N;

    auto sum = 0, min = -1;

    for (int i = M; i <= N; ++i) {
        if (arr[i] == 0) {
            sum += i;
            if (min == -1) min = i;
        }
    }

    if (min != -1) cout << sum << endl;
    cout << min << endl;
    return 0;
}