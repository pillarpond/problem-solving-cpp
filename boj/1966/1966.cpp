//queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    auto T = 0;
    cin >> T;

    auto N = 0, M = 0, num = 0;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> M;

        priority_queue<int, vector<int>, less<int> > pq;
        queue<pair<int, int> > q;

        for (int j = 0; j < N; ++j) {
            cin >> num;
            pq.push(num);
            q.push(make_pair(j, num));
        }

        auto cnt = 1;
        while (!q.empty()) {
            auto idx = q.front().first;
            auto val = q.front().second;
            q.pop();

            if(val == pq.top()) {
                if (idx == M) {
                    cout << cnt << endl;
                }
                pq.pop();
                cnt++;
            } else {
                q.push(make_pair(idx, val));
            }
        }
    }

    return 0;
}