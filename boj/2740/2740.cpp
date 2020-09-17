//math

#include <iostream>

using namespace std;

int A[101][101] = {0};
int B[101][101] = {0};

int main() {
    auto N = 0, M = 0, K = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= K; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            auto sum = 0;
            for (int k = 1; k <= M; ++k) {
                sum += A[i][k] * B[k][j];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
}