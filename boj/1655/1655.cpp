//prio queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int> > minq;
    priority_queue<int, vector<int>, less<int> > maxq;

    int N;
    cin >> N;

    while (N-- > 0) {
        int num;
        cin >> num;

        if (maxq.size() <= minq.size()) {
            maxq.push(num);
        } else {
            minq.push(num);
        }

        if (maxq.empty() || minq.empty()) {
            cout << maxq.top() << "\n";
            continue;
        }

        while (maxq.top() > minq.top()) {
            int num1 = maxq.top();
            int num2 = minq.top();

            maxq.pop();
            minq.pop();
            maxq.push(num2);
            minq.push(num1);
        }

        cout << maxq.top() << "\n";
    }
    return 0;
}