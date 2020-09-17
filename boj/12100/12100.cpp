//dfs, bfs

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX = 21;

int board[MAX][MAX] = {0,};
int N;

void up() {
    for (int c = 0; c < N; ++c) {
        queue<int> q;
        for (int r = 0; r < N; ++r) { 
            if (board[r][c] != 0) {
                q.push(board[r][c]);
                board[r][c] = 0;
            }
        }

        int prev = 0;
        int r = 0;
        q.push(0);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (prev == now) {
                prev *= 2;
                now = 0;
            }

            if (prev != 0) board[r++][c] = prev;
            prev = now;
        }
    }
}

void down() {
    for (int c = 0; c < N; ++c) {
        queue<int> q;
        for (int r = N - 1; r >= 0; --r) { 
            if (board[r][c] != 0) {
                q.push(board[r][c]);
                board[r][c] = 0;
            }
        }

        int prev = 0;
        int r = N - 1;
        q.push(0);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (prev == now) {
                prev *= 2;
                now = 0;
            }

            if (prev != 0) board[r--][c] = prev;
            prev = now;
        }
    }
}

void left() {
    for (int r = 0; r < N; ++r) {
        queue<int> q;
        for (int c = 0; c < N; ++c) { 
            if (board[r][c] != 0) {
                q.push(board[r][c]);
                board[r][c] = 0;
            }
        }

        int prev = 0;
        int c = 0;
        q.push(0);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (prev == now) {
                prev *= 2;
                now = 0;
            }

            if (prev != 0) board[r][c++] = prev;
            prev = now;
        }
    }
}

void right() {
    for (int r = 0; r < N; ++r) {
        queue<int> q;
        for (int c = N - 1; c >= 0; --c) { 
            if (board[r][c] != 0) {
                q.push(board[r][c]);
                board[r][c] = 0;
            }
        }

        int prev = 0;
        int c = N - 1;
        q.push(0);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (prev == now) {
                prev *= 2;
                now = 0;
            }

            if (prev != 0) board[r][c--] = prev;
            prev = now;
        }
    }
}

int dfs(int cnt) {
    if (cnt >= 5) {
        int num = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                num = max(num, board[i][j]);
            }
        }
        return num;
    }

    int res = 0;
    int tmp[MAX][MAX] = {0,};
    memcpy(tmp, board, sizeof(board));

    up();
    res = max(res, dfs(cnt + 1));
    memcpy(board, tmp, sizeof(tmp));

    down();
    res = max(res, dfs(cnt + 1));
    memcpy(board, tmp, sizeof(tmp));

    left();
    res = max(res, dfs(cnt + 1));
    memcpy(board, tmp, sizeof(tmp));

    right();
    res = max(res, dfs(cnt + 1));
    memcpy(board, tmp, sizeof(tmp));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0) << "\n";

    return 0;
}