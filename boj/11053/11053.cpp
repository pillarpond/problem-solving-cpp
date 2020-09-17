//dp

#include <iostream>
using namespace std;

int arr[1001] = {0};
unsigned long sum[1001] = {0};
auto n = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = n; i >= 0; --i) {
        sum[i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            if (arr[i] < arr[j] && sum[i] <= sum[j]) {
                sum[i] = sum[j] + 1;
            }
        }
    }

    cout << sum[0] - 1 << endl;
    return 0;
}