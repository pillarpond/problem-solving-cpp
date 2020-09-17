//greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto N = 0;
    cin >> N;

    auto P = 0;
    vector<int> v;

    for (int i = 0; i < N; ++i) {
        cin >> P;
        v.push_back(P);
    }

    sort(v.begin(), v.end());

    auto sum = 0, delay = 0;

    for (int i = 0; i < v.size(); ++i) {
        delay += v[i];
        sum += delay;
    }

    cout << sum << endl;
    return 0;
}