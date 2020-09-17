//math

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        v.push_back(num);
    }
    sort(v.begin(), v.end());

    vector<int> diff(N - 1);
    for (int i = 1; i < N; ++i) {
        diff[i - 1] = v[i] - v[i - 1];
    }

    int cand = gcd(diff[0], diff[1]);
    for (int i = 2; i < N - 1; ++i) {
        cand = gcd(cand, diff[i]);
    }

    int cnt = 0;
    int prev = v[0];
    for (int i = 1; i < N; ++i) {
        int now = v[i];
        cnt += (now - prev - cand) / cand;
        prev = now;
    }

    cout << cnt << "\n";
    return 0;
}