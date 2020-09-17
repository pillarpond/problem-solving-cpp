//greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    auto N = 0, cnt = 1;
    cin >> N;

    auto start = 0, end = 0;
    vector<pair<int, int> > v;

    for (int i = 1; i <= N; ++i) {
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    sort(v.begin(), v.end(), cmp);

    end = v[0].first;

    for (int i = 1; i < v.size(); ++i) {
        if (end <= v[i].second) {
            end = v[i].first;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}