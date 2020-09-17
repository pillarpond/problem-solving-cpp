//dp

#include <iostream>
using namespace std;

int arr[100001] = {0};
long long sum[100001] = {0};
auto n = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        sum[i] = max(sum[i - 1] + arr[i], (long long) arr[i]);
    }

    long long max = sum[1];
    for (int i = 2; i <= n; ++i) {
        if (sum[i] > max) {
            max = sum[i];
        }
    }

    cout << max << endl;
    return 0;
}