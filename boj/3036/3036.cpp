//math

#include <iostream>

using namespace std;

int arr[101] = {0};

int GCD (int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    auto N = 0;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    int gcd = 0;
    for (int i = 2; i <= N; ++i) {
        gcd = GCD(arr[1], arr[i]);
        cout << arr[1] / gcd << "/" << arr[i] / gcd << "\n";
    }

    return 0;
}