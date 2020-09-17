//dp

#include <iostream>
using namespace std;

unsigned int triangle[500][500] = {0};
unsigned long sum[500][500] = {0};
auto n = 0;

int solve(int row, int col) {
    if (col == n) return 0;
    unsigned long& ret = sum[row][col];

    if (ret > 0) return ret;

    ret = triangle[row][col] + max(solve(row, col + 1), solve(row + 1, col + 1));
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[j][i];
        }
    }

    cout << solve(0, 0) << endl;
    return 0;
}