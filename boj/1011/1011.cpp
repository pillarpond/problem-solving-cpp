//math

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T = 0;
    cin >> T;

    queue<long long> q;

    auto x = 0, y = 0;
    while (T--) {
        cin >> x >> y;

        auto diff = y - x, cnt = 0;
        long long sum = 0;
        while (diff > sum) {
            sum += cnt / 2 + 1;
            cnt++;
        }
        q.push(cnt);
    }

    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}