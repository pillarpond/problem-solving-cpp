//bsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 1;
    int right = v[N - 1] - v[0];
    int ans = 0;

    while (right >= left) {
        int mid = (right + left) / 2;
        int cnt = 1;
        int start = v[0];

        for (int i = 1; i < N; ++i) {
            int d = v[i] - start;
            if (d >= mid) {
                cnt++;
                start = v[i];
            }
        }

        if (cnt >= C) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}