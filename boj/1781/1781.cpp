//greedy

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int N;

vector<pii> ramen;

long long greedy() {
    priority_queue<int> pq;
    long long total = 0; 
    int index = 0;

    for (int i = N; i > 0; --i) {
        while (index < N && -ramen[index].first >= i) {
            pq.push(ramen[index].second);
            ++index;
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

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int d, c;
        cin >> d >> c;
        ramen.push_back({-d, c});
    }

    sort(ramen.begin(), ramen.end());

    cout << greedy() << "\n";
    return 0;
}