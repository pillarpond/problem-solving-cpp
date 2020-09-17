//greedy

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;

        pq.push(A);
    }

    int prev = -1;
    auto sum = 0ULL;
    auto x = 0LL;

    while(!pq.empty()) {
        long long curr = pq.top();
        pq.pop();

        if (prev != -1 && prev - curr <= 1) {
            if (x == 0) {
                x = curr;
            } else {
                sum += x * curr;
                x = 0;
            }
            prev = -1;
        } else {
            prev = curr;
        }
    }

    cout << sum << "\n";
    return 0;
}