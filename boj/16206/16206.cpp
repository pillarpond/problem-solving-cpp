//greedy

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    priority_queue<pair<double,int> > pq;

    for (int i = 0 ; i < N; ++i) {
        int num;
        cin >> num;

        if (num < 10) continue;
        if (num == 10) {
            cnt++;
        } else {
            int cut = (num - 1) / 10;
            double part = num / 10;
            pq.push({part/cut, cut});
        }
    }

    while(!pq.empty()) {
        int cut;
        double prior;

        tie(prior, cut) = pq.top();
        pq.pop();

        cnt += prior * min(M, cut);
        M -= cut;

        if (M <= 0) break;
    }

    cout << cnt << "\n";
    return 0;
}