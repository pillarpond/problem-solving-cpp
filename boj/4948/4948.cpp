//sieve

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

static const int MAX = 123456 * 2;
bool arr[MAX + 1] = {0};

int main() {
    arr[0] = arr[1] = true;
    for (int i = 2; i <= sqrt(MAX); ++i) {
        if (arr[i] == false) {
            for (int j = i; i * j <= MAX; ++j) {
                arr[i * j] = true;
            }
        }
    }

    auto n = 0, cnt = 0;
    queue<int> q;
    while(1) {
        cin >> n;
        if (n == 0) break;

        cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (!arr[i]) cnt++;
        }
        q.push(cnt);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}