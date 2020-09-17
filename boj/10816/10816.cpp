//bsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        auto lower = lower_bound(v.begin(), v.end(), num);
        auto upper = upper_bound(v.begin(), v.end(), num);
        cout << upper - lower << " ";
    }
    cout << "\n";
    return 0;
}