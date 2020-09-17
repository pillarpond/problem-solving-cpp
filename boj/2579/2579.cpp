//dp

#include <iostream>
using namespace std;

int arr[301] = {0};
long sum[301] = {0};
auto n = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sum[1] = arr[1];
    sum[2] = sum[1] + arr[2];
    sum[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= n; i++) {
        sum[i] = max(sum[i - 3] + arr[i - 1] + arr[i], sum[i - 2] + arr[i]);
    }

    cout << sum[n] << endl;
    return 0;
}