//dfs

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[101] = {0,};

int pls, mns, mul, dvd;
long long minsum = 987654321, maxsum = -987654321;

void dfs(int index, long long sum) {
    if (index == N) {
        minsum = min(minsum, sum);
        maxsum = max(maxsum, sum);
        return;
    }

    if (pls > 0) {
        --pls;
        dfs(index + 1, sum + arr[index]);
        ++pls;
    }

    if (mns > 0) {
        --mns;
        dfs(index + 1, sum - arr[index]);
        ++mns;
    }

    if (mul > 0) {
        --mul;
        dfs(index + 1, sum * arr[index]);
        ++mul;
    }

    if (dvd > 0) {
        --dvd;
        dfs(index + 1, sum / arr[index]);
        ++dvd;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> pls >> mns >> mul >> dvd;

    dfs(1, arr[0]);
    cout << maxsum << "\n";
    cout << minsum << "\n";

    return 0;
}