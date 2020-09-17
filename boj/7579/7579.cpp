//dp

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 101;

int N, M;
int m[MAX] = {0,};
int c[MAX] = {0,};
int dp[MAX * MAX] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < N; ++i) cin >> m[i];
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
        sum += c[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = sum; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
        }
    }

    int cost = 0;
    while(dp[cost] < M) {
        if (cost >= sum) break;
        ++cost;
    }

    cout << cost << "\n";

    return 0;
}