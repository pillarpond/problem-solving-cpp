//greedy

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int n;

vector<pii> vec;

int greedy() {
    priority_queue<int> pq;

    int total = 0;
    int it = 0;

    for (int i = n; i > 0; --i) {
        while (it < n && -vec[it].first >= i) {
            pq.push(vec[it].second);
            ++it;
            continue;
        }

        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p, d;
        cin >> p >> d;

        vec.push_back({-d, p});
    }

    sort(vec.begin(), vec.end());

    cout << greedy() << "\n";
    return 0;
}