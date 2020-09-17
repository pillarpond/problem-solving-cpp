//dp

#include <iostream>
using namespace std;

int arr[10001] = {0};
unsigned long sum[10001] = {0};
auto n = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    sum[1] = arr[1];
    sum[2] = sum[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        sum[i] = max(max(sum[i - 3] + arr[i - 1] + arr[i], sum[i - 1]), sum[i - 2] + arr[i]);
    }

    cout << sum[n] << endl;
    return 0;
}