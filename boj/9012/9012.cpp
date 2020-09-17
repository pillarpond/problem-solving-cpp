//stack

#include <iostream>
#include <stack>

using namespace std;

int main() {
    auto T = 0;
    cin >> T;

    string str;
    bool check;

    for (int i = 0; i < T; ++i) {
        cin >> str;

        check = true;
        stack<int> s;

        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '(') {
                s.push(0);
            } else {
                if (s.empty()) {
                    check = false;
                    break;
                }
                s.pop();
            }
        }

        if (!check || !s.empty()) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}