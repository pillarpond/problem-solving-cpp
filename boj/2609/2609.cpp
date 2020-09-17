//math

#include <iostream>

using namespace std;

int arr[10001][2] = {0};

int main() {
    auto a = 0, b = 0;
    cin >> a >> b;

    auto num = max(a, b);
    arr[1][0] = arr[1][1] = 1;

    for (int i = 2; i <= a; ++i) {
        while (a % i == 0) {
            a /= i;
            arr[i][0]++;
        }
    }

    for (int i = 2; i <= b; ++i) {
        while (b % i == 0) {
            b /= i;
            arr[i][1]++;
        }
    }

    long long sum = 1;
    for (int i = 2; i <= num; ++i) {
        if (arr[i][0] > 0 && arr[i][1] > 0) {
            for (int j = 0; j < min(arr[i][0], arr[i][1]); ++j) sum *= i;
        }
    }

    cout << sum << endl;

    sum = 1;
    for (int i = 2; i <= num; ++i) {
        if (arr[i][0] != 0 || arr[i][1] != 0) {
            for (int j = 0; j < max(arr[i][0], arr[i][1]); ++j) sum *= i;
        }
    }

    cout << sum << endl;

    return 0;
}