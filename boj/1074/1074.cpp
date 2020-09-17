//dnc

#include <iostream>

using namespace std;

int dnc(int n, int r, int c) {
    if (n == 2) return 2 * r + c;

    int nn = n / 2;
    return nn * nn * (2 * (r / nn) + c / nn) + dnc(nn, r % nn, c % nn);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c;

    cout << dnc(1 << N, r, c) << "\n";

    return 0;
}