//greedy

#include <iostream>

using namespace std;

constexpr int MAX = 51;

char A[MAX][MAX] = {0,};
bool diff[MAX][MAX] = {0,};

int N, M;

void reverse(int r, int c) {
    for (int i = r; i < r + 3; ++i) {
        for (int j = c; j < c + 3; ++j) {
            diff[i][j] = !diff[i][j];
        }
    }
}

int greedy() {
    int cnt = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < M - 2; ++j) {
            if (diff[i][j]) {
                reverse(i, j);
                ++cnt;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (diff[i][j]) return -1;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;

            diff[i][j] = (A[i][j] != c) ? true : false;
        }
    }

    cout << greedy() << "\n";
    return 0;
}