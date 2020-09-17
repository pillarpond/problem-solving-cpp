//greedy

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int N, K;

vector<pii> gem;
vector<int> bag;

long long greedy() {
    priority_queue<int> pq;

    long long total = 0;
    int index = 0;

    for (int i = 0; i < K; ++i) {
        while(index < N && bag[i] >= gem[index].first) {
            pq.push(gem[index].second);
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

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int m, v;
        cin >> m >> v;
        gem.push_back({m, v});
    }

    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        bag.push_back(c);
    }

    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    cout << greedy() << "\n";

    return 0;
}