//math

#include <iostream>

using namespace std;

constexpr int MAX = 101;

int arr[MAX] = {0,};

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        long long sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                sum += gcd(arr[i], arr[j]);
            }
        }

        cout << sum << "\n";
    }
    return 0;
}