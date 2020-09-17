//greedy

#include <iostream>

using namespace std;

int main() {
    auto N = 0, res = 0;
    cin >> N;

    for (int i = N / 5; i >= 0; --i) {
        res = N - 5 * i;
        if (res % 3 == 0) {
            cout << i + res / 3 << endl; 
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}