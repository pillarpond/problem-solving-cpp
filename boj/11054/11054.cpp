//dp

#include <iostream>
using namespace std;

int arr[1001] = {0};
unsigned long sum[1001][2] = {0};
auto n = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        sum[i][0] = 1;
        for (int j = i - 1; j > 0; --j) {
            if (arr[i] > arr[j] && sum[i][0] <= sum[j][0]) {
                sum[i][0] = sum[j][0] + 1;
            }
        }
    }

    for (int i = n; i > 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
            if (arr[i] > arr[j] && sum[i][1] <= sum[j][1]) {
                sum[i][1] = sum[j][1] + 1;
            }
        }
    }

    unsigned long max = 0;
    for (int i = 1; i <=n; ++i) {
        unsigned long res = sum[i][0] + sum[i][1];
        if (max < res) {
            max = res;
        }
    }

    cout << max << endl;
    return 0;
}