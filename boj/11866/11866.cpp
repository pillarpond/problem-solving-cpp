//queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    auto N = 0, K = 0;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    cout << "<";
    while (1) {
        for (int i = 0; i < K - 1; ++i) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if (q.empty()) {
            cout << ">\n";
            break;
        } else {
            cout << ", ";
        }
    }

    return 0;
}