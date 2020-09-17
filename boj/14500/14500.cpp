//brute force

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

constexpr int MAX = 501;

pii tetris[19][4] = {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 
                    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
                    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
                    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
                    {{0, 0}, {0, -1}, {1, -1}, {2, -1}},
                    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
                    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
                    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 0}, {-1, 0}, {-1, 1}, {-1, 2}},
                    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
                    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
                    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
                    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
                    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
                    {{0, 0}, {1, 0}, {2, 0}, {1, -1}},
                    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
                    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}}};

int N, M;
int arr[MAX][MAX] = {0,};

int check(int x, int y, int index) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        int dx = x + tetris[index][i].first;
        int dy = y + tetris[index][i].second;

        if (dx < 0 || dx >= M || dy < 0 || dy >= N) return -1;
        sum += arr[dy][dx];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < 19; ++k) {
                res = max(res, check(j, i, k));
            }
        }
    }
    cout << res << "\n";
    return 0;
}