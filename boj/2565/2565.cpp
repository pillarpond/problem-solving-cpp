//dp

#include <iostream>
using namespace std;

int arr[501] = {0};
unsigned long sum[501] = {0};
auto n = 0;

int main() {
    cin >> n;
    auto idx = 0, max = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> idx;
        cin >> arr[idx];

        if (arr[idx] > max) max = arr[idx];
    }

    for (int i = max; i >= 0; --i) {
        sum[i] = 1;
        for (int j = i + 1; j <= max; ++j) {
            if (arr[j] != 0 && arr[i] < arr[j] && sum[i] <= sum[j]) {
                sum[i] = sum[j] + 1;
            }
        }
    }

    cout << n - sum[0] + 1 << endl;
    return 0;
}