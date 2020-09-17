//sieve

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

static const int MAX = 10000;
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

    auto n = 0, T = 0;
    queue<pair<int,int> > q;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;
    
        for (int i = n / 2; i <= n; ++i) {
            if (!arr[i] && !arr[n - i]) {
                q.push(make_pair(n - i, i));
                break;
            }
        }
    }

    auto num = 0;
    while (!q.empty()) {
        cout << q.front().first << " " << q.front().second << endl;
        q.pop();
    }
    return 0;
}