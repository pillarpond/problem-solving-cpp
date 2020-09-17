//deque

#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
	cin.sync_with_stdio(false);

    auto N = 0;
    cin >> N;

    string cmd;
    deque<int> q;
    int num = 0;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push_front") {
            cin >> num;
            q.push_front(num);
        } else if (cmd == "push_back") {
            cin >> num;
            q.push_back(num);
        } else if (cmd == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (cmd == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "empty") {
            if (q.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (cmd == "pop_front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
                q.pop_back();
            }
        }
    }
    return 0;
}