//bsearch

#include <iostream>

using namespace std;

constexpr int MAX = 10001;

int arr[MAX] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N;

    int right = -1;
    int left = 0;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }

    cin >> M;
    int ans = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < N; ++i) {
            if (arr[i] > mid) sum += mid;
            else sum += arr[i];
        }

        if (sum > M) {
            right = mid - 1;
        } else {
            ans = max(ans, mid);
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}