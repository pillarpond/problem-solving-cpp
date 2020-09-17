//stack

#include <iostream>
#include <stack>

using namespace std;

int main() {
    auto N = 0;
    cin >> N;

    string cmd;
    stack<int> s;
    int num = 0;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> num;
            s.push(num);
        } else if (cmd == "top") {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        } else if (cmd == "size") {
            cout << s.size() << "\n";
        } else if (cmd == "empty") {
            if (s.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (cmd == "pop") {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
    return 0;
}