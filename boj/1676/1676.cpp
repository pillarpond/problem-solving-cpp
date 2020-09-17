//math

#include <iostream>

using namespace std;

int main() {
    auto N = 0;
    cin >> N;

    auto two = 0, five = 0, num = 0;
    for (int i = 1; i <= N; ++i) {
        num = i;
        while (num % 5 == 0) {
            num /= 5;
            five++;
        }

        while (num % 2 == 0) {
            num /= 2;
            two++;
        }
    }

    cout << min(two, five) << endl;

    return 0;
}