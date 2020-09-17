//bsearch

#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int left = 1;
    int right = K;
    int ans = 0;

    while (right >= left) {
        int mid = (right + left) / 2;
        int cnt = 0;

        for (int i = 1; i <= N; ++i) {
            cnt += min(mid / i, N);
        }

        if (cnt >= K) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}