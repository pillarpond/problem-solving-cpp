//queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    auto N = 0;
    cin >> N;

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    auto num = 0;
    while (!q.empty()) {
        num = q.front();
        q.pop();

        if (q.empty()) break;

        num = q.front();
        q.push(num);
        q.pop();
    }

    cout << num << endl;
    return 0;
}