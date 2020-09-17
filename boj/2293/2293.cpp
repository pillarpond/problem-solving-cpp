//dp

#include <iostream>

using namespace std;

int arr[100] = {0};
int cache[10001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cache[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (arr[i] <= j) {
                cache[j] += cache[j - arr[i]];
            }
        }
    }

    cout << cache[k] << "\n";
    return 0;
}