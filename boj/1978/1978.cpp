//sieve

#include <iostream>

using namespace std;

int arr[1001] = {0};

int main() {
    auto N = 0;
    cin >> N;

    arr[0] = arr[1] = 1;
    for (int i = 2; i <= 1000; ++i) {
        if (arr[i] == 0) {
            for (int j = i; i * j <= 1000; ++j) {
                arr[i * j] = 1;
            }
        }
    }

    auto cnt = 0, num = 0;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        if (arr[num] == 0) cnt++;
    }

    cout << cnt << endl;
    return 0;
}