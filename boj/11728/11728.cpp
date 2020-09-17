//sort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int> > pq;

    int N, M, num;
    cin >> N >> M;

    for (int i = 0; i < N + M; ++i) {
        cin >> num;
        pq.push(num);
    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
    return 0;
}