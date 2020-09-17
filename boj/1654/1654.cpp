//bsearch

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool check(vector<int> &v, int num, int min) {
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        cnt += v[i] / num;
    }

    return cnt >= min ? true : false;
}

int main() {
    int K, N;
    cin >> K >> N;

    int max = 0;
    vector<int> v(K);
    for (int i = 0; i < K; ++i) {
        cin >> v[i];
        if (max < v[i]) max = v[i];
    }

    long long left = 1, right = max;
    int ans = 0;

    while (right - left >= 0) {
        long long mid = (left + right) / 2;

        if (check(v, mid, N)) {
            if (ans < mid) ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}