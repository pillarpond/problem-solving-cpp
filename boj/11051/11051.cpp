//dp

#include <iostream>

using namespace std;

static const int MOD = 10007;
int arr[1001][1001] = {0};

int main() {
    auto N = 0, K = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % MOD;
            }
        }
    }

    cout << arr[N][K] << endl;
    return 0;
}