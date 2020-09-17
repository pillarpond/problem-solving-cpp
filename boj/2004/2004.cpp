//math

#include <iostream>

using namespace std;

long long count(int n, int d) {
    long long cnt = 0;
    for (long long i = d; i <= n; i *= d) {
        cnt += n / i;
    }

    return cnt;
}

int main() {
    auto n = 0, m = 0;
    cin >> m >> n;

    long long two = count(m, 2) - count(n, 2) - count(m - n, 2);
    long long five = count(m, 5) - count(n, 5) - count(m - n, 5);

    cout << min(two, five) << endl;
    return 0;
}