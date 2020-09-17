//dp

#include <iostream>

using namespace std;

int arr[500] = {0};
int sum[501] = {0};
int cache[501][501] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int K;
        cin >> K;

        for (int i = 0; i < K; ++i) {
            cin >> arr[i];
            sum[i + 1] = arr[i] + sum[i];
        }

        for (int d = 1; d < K; ++d) {
            for (int s = 1; s + d <= K; ++s) {
                int e = s + d;
                cache[s][e] = 1000000007;

                for (int mid = s; mid < e; ++mid) {
                    cache[s][e] = min(cache[s][e], cache[s][mid] + cache[mid + 1][e] + sum[e] - sum[s - 1]);
                }
            }
        }

        cout << cache[1][K] << "\n";
    }
    return 0;
}