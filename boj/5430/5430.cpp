//deque

#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
	cin.sync_with_stdio(false);

    auto T = 0;
    cin >> T;

    string cmd, x;
    auto n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> cmd >> n >> x;

        deque<int> dq;
        bool forward = true;
        bool error = false;

        auto tmp = 0;
        for (int j = 0; j < x.size(); ++j) {
            if (n == 0) break;

            if (x[j] == '[') {
                continue;
            } else if (x[j] >= '0' && x[j] <= '9') {
                int num = x[j] - '0';
                tmp = tmp * 10 + num;
            }
            else if (x[j] == ',') {
                dq.push_back(tmp);
                tmp = 0;
            }
            else if (x[j] == ']') {
                dq.push_back(tmp);
                break;
            }
        }

        for (int j = 0; j < cmd.size(); ++j) {
            if (cmd[j] == 'R') {
                forward = !forward;
            } else if (cmd[j] == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (forward) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        while (!dq.empty()) {
            if (forward) {
                cout << dq.front();
                dq.pop_front();
            } else {
                cout << dq.back();
                dq.pop_back();
            }
            if (!dq.empty()) {
                cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}