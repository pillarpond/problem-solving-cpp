//brute force

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool arr[201][201] = {0,};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
    }

    int cnt = 0;
    for (int i = 1; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i][j]) continue;
            for (int k = j + 1; k <= N; ++k) {
                if (arr[i][k] || arr[j][k]) continue;
                ++cnt;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}