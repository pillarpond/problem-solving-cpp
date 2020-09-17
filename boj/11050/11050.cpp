//math

#include <iostream>

using namespace std;

int arr[11] = {0};

int main() {
    auto N = 0, K = 0;
    cin >> N >> K;

    arr[0] = arr[1] = 1;

    for (int i = 2; i <= N; ++i) {
        arr[i] = arr[i - 1] * i;
    }

    cout << arr[N] / (arr[N - K] * arr[K]) << endl;
    return 0;
}