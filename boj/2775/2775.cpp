//math

#include <iostream>
#include <queue>

using namespace std;

int arr[15][15] = {0};

int main() {
    auto T = 0;
    cin >> T;

    queue<int> q;

    for (int i = 1; i <= 14; ++i) {
        arr[0][i] = i;
    }

    for (int i = 1; i <= 14; ++i) {
        for (int j = 1; j <= 14; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    auto k = 0, n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> k >> n;
        q.push(arr[k][n]);
    }

    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}