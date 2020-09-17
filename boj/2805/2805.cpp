//bsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &v, int mid, int num) {
    long long sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > mid) sum += v[i] - mid;
    }

    if (sum >= num) return true;
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    int max = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (max < v[i]) max = v[i];
    }

    sort(v.begin(), v.end());

    int left = 1, right = max;
    int ans = 0;
    while(right - left >= 0) {
        int mid = (right + left) / 2;

        if (check(v, mid, M)) {
            if (ans < mid) ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}