//sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const string &s1, const string &s2) {
    return s1 + s2 > s2 + s1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> K >> N;

    vector<string> v;
    int repeat = -1;

    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;

        repeat = max(repeat, num);
        v.push_back(to_string(num));
    }

    sort(v.begin(), v.end(), cmp);

    for (string s : v) {
        cout << s;

        if (atoi(s.c_str()) == repeat) {
            repeat = -1;
            for (int i = 0; i < N - K; ++i) {
                cout << s;
            }
        }
    }
    cout << "\n";

    return 0;
}