//dp

#include <iostream>
using namespace std;

int W[101] = {0};
int V[101] = {0};
int sum[101][100001] = {0};

auto N = 0, K = 0;

int solve(int index, int weight) {
    if (index > N) return 0;

    int& ret = sum[index][weight];
    if (ret > 0) return ret;

    if (weight < W[index]) {
        ret = solve(index + 1, weight);
    } else {
        ret = max(solve(index + 1, weight), solve(index + 1, weight - W[index]) + V[index]);
    }

    return ret;
}

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> W[i] >> V[i];
    }

    cout << solve(0, K) << endl;
    return 0;
}