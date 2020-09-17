//stack

#include <iostream>
#include <stack>

using namespace std;

int main() {
    auto K = 0;
    cin >> K;

    auto num = 0;
    long long sum = 0;
    stack<int> s;

    for (int i = 0; i < K; ++i) {
        cin >> num;

        if (num == 0) {
            sum -= s.top();
            s.pop();
        } else {
            sum += num;
            s.push(num);
        }
    }

    cout << sum << endl;

    return 0;
}