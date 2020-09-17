//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 101;

int arr[MAX] = {0,};

int N;

int pls;
int mns;
int dvd;
int mul;

long long res_max = -1000000001;
long long res_min = 1000000001;

void dfs(int index, long long sum) {
    if (index == N) {
        res_max = max(res_max, sum);
        res_min = min(res_min, sum);
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

    cout << res_max << "\n";
    cout << res_min << "\n";

    return 0;
}