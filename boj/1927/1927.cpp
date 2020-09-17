//prio queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num;
    priority_queue<int,vector<int>,greater<int> > pq;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }

    return 0;
}