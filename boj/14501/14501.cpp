//dfs

#include <iostream>

using namespace std;

constexpr int MAX = 16;

int N;

int T[MAX] = {0,};
int P[MAX] = {0,};

int dfs(int day, int profit) {
    if (day >= N) return profit;
    int res = dfs(day + 1, profit);

    if (day + T[day] <= N) res = max(res, dfs(day + T[day], profit + P[day]));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> P[i];
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}