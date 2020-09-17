//stack

#include <iostream>
#include <stack>

using namespace std;
long long arr[100001] = {0};

int main() {
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        stack<int> s;
        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            while(!s.empty() && (arr[s.top()] > arr[i])) {
                long long h = arr[s.top()];
                s.pop();

                int w = i - 1;
                if (!s.empty()) {
                    w = i - s.top() - 1;
                }
                if (ans < h * w) {
                    ans = h * w;
                }
            }
            s.push(i);
        }

        while(!s.empty()) {
            long long h = arr[s.top()];
            s.pop();

            int w = n;
            if (!s.empty()) {
                w = n - s.top();
            }
            if (ans < h * w) {
                ans = h * w;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}