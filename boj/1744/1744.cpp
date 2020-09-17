//greedy

#include <iostream>
#include <queue>

using namespace std;

int N;

priority_queue<int> pq;
priority_queue<int> nq;

bool zero = false;
int one = 0;

int greedy() {
    int total = 0;

    while(!pq.empty()) {
        int prev = pq.top();
        pq.pop();

        if (!pq.empty()) {
            int now = pq.top();
            pq.pop();

            total += prev * now;
        } else {
            total += prev;
        }
    }

    if (one) total += one;

    while(!nq.empty()) {
        int prev = nq.top();
        nq.pop();

        if (!nq.empty()) {
            int now = nq.top();
            nq.pop();

            total += prev * now;
        } else if (!zero) {
            total -= prev;
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        if (n > 1) pq.push(n);
        else if (n == 1) ++one;
        else if (n == 0) zero = true;
        else nq.push(-n);
    }

    cout << greedy() << "\n";
    return 0;
}