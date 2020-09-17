//greedy

#include <iostream>
using namespace std;

int arr[11] = {0};

int main() {
    auto N = 0, K = 0, cnt = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = N; i > 0; --i) {
        while (K >= arr[i]) {
            K -= arr[i];
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}