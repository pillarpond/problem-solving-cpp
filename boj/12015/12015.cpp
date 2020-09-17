//bsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v1(N);
    for (int i = 0; i < N; ++i) {
        cin >> v1[i];
    }

    vector<int> v2;
    v2.push_back(v1[0]);
    for (int i = 1; i < N; ++i) {
        if (v1[i] > v2.back()) {
            v2.push_back(v1[i]);
        } else {
            auto low = lower_bound(v2.begin(), v2.end(), v1[i]);
            *low = v1[i];
        }
    }

    cout << v2.size() << endl;
    return 0;
}