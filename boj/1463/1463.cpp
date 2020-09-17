//dp

#include <iostream>
using namespace std;

int arr[1000001] = {0};
auto N = 0;

int main() {
    cin >> N;

    arr[2] = arr[3] = 1;

    for (int i = 4; i <= N; i++) {
        if (i % 3 == 0) {
            arr[i] = min(arr[i / 3] + 1, arr[i - 1] + 1);
            continue;
        }
        if (i % 2 == 0) {
            arr[i] = min(arr[i / 2] + 1, arr[i - 1] + 1);
            continue;
        }
        arr[i] = arr[i - 1] + 1;
    }

    cout << arr[N] << endl;
    return 0;
}