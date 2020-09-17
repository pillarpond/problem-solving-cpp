//stack

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

char cmd[200000] = {0};

int main() {
    auto n = 0;
    cin >> n;

    stack<int> s;
    vector<char> v;
    int num = 0, head = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> num;

        if (num > head) {
            for (int j = head + 1; j <= num; ++j) {
                s.push(j);
                v.push_back('+');
            }
            head = num;
        }
        
        if (s.top() != num) {
            cout << "NO" << "\n";
            return 0;
        }

        s.pop();
        v.push_back('-');
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\n";
    }
}