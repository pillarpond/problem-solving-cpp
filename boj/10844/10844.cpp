//dp

#include <iostream>
using namespace std;

const int MOD = 1000000000;
int arr[101][10] = {0};
auto N = 0;

int main() {
    cin >> N;

    arr[1][1] = arr[1][2] = arr[1][3] = arr[1][4] = 
    arr[1][5] = arr[1][6] = arr[1][7] = arr[1][8] =
    arr[1][9] = 1;

    for (int i = 2; i <= N; i++) {
        arr[i][0] = arr[i - 1][1];
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % MOD;
        arr[i][2] = (arr[i - 1][1] + arr[i - 1][3]) % MOD;
        arr[i][3] = (arr[i - 1][2] + arr[i - 1][4]) % MOD;
        arr[i][4] = (arr[i - 1][3] + arr[i - 1][5]) % MOD;
        arr[i][5] = (arr[i - 1][4] + arr[i - 1][6]) % MOD;
        arr[i][6] = (arr[i - 1][5] + arr[i - 1][7]) % MOD;
        arr[i][7] = (arr[i - 1][6] + arr[i - 1][8]) % MOD;
        arr[i][8] = (arr[i - 1][7] + arr[i - 1][9]) % MOD;
        arr[i][9] = arr[i - 1][8];
    }

    auto sum = 0L;
    for (int i = 0; i < 10; i++) {
        sum += arr[N][i];
    }

    cout << sum % MOD << endl;
    return 0;
}