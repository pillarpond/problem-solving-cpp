//dp

#include <iostream>
using namespace std;

unsigned long sum[1001][3] = {0};

int main() {
    auto N = 0;
    cin >> N;

    auto r = 0, g = 0, b = 0;

    for (int i = 1; i <= N; i++) {
        cin >> r >> g >> b;
        sum[i][0] = min(sum[i - 1][1] + r, sum[i - 1][2] + r);
        sum[i][1] = min(sum[i - 1][0] + g, sum[i - 1][2] + g);
        sum[i][2] = min(sum[i - 1][0] + b, sum[i - 1][1] + b);
    }

    cout << min(min(sum[N][0],sum[N][1]), sum[N][2]) << endl;
    return 0;
}