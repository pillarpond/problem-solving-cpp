//stack

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    bool check;

    while (1) {
        getline(cin, str);

        if (str == ".") {
            break;
        }

        check = true;
        stack<int> s;

        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '(') {
                s.push(0);
            } else if (str[j] == ')') {
                if (s.empty() || s.top() != 0) {
                    check = false;
                    break;
                }
                s.pop();
            } else if (str[j] == '[') {
                s.push(1);
            } else if (str[j] == ']') {
                if (s.empty() || s.top() != 1) {
                    check = false;
                    break;
                }
                s.pop();
            }
        }

        if (!check || !s.empty()) {
            cout << "no" << "\n";
        } else {
            cout << "yes" << "\n";
        }
    }
    return 0;
}