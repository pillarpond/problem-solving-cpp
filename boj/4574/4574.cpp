//dfs

#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

int sudoku[9][9] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N;
int U, V;
int cnt = 0;

bool tile[10][10] = {0,};

string LU, LV;

bool finished = false;
vector<pii> todo;

bool check(int r, int c, int n) {
    for (int i = 0; i < 9; ++i) {
        if (sudoku[r][i] == n) return false;
        if (sudoku[i][c] == n) return false;
    }

    int rr = r - (r % 3);
    int cc = c - (c % 3);
    for (int i = rr; i < rr + 3; ++i) {
        for (int j = cc; j < cc + 3; ++j) {
            if (sudoku[i][j] == n) return false;
        }
    }

    return true;
}

void print() {
    std::cout << "Puzzle " << ++cnt << "\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j];
        }
        cout << "\n";
    }
}

void dfs(int index) {
    if (finished) return;

    if (index == todo.size()) {
        finished = true;
        print();
    }

    int x, y;
    tie(y, x) = todo[index];

    if (sudoku[y][x] == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (!check(y, x, i)) continue;

            for (int j = 1; j <= 9; ++j) {
                if (i == j) continue;
                if (tile[i][j]) continue;

                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9) continue;
                    if (sudoku[ny][nx] != 0) continue;
                    if (!check(ny, nx, j)) continue;

                    tile[i][j] = tile[j][i] = true;
                    sudoku[y][x] = i;
                    sudoku[ny][nx] = j;
                    dfs(index + 1);
                    sudoku[y][x] = sudoku[ny][nx] = 0;
                    tile[i][j] = tile[j][i] = false;
                }
            }
        }
    } else {
        dfs(index + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        cin >> N;
        if (N == 0) break;

        finished = false;
        memset(tile, 0, sizeof(tile));
        memset(sudoku, 0, sizeof(sudoku));
        todo.clear();

        for (int i = 0; i < N; ++i) {
            cin >> U >> LU >> V >> LV;
            int y = LU[0] - 'A';
            int x = LU[1] - '1';
            sudoku[y][x] = U;

            y = LV[0] - 'A';
            x = LV[1] - '1';
            sudoku[y][x] = V;

            tile[U][V] = tile[V][U] = true;
        }

        for (int i = 1; i <= 9; ++i) {
            string str;
            cin >> str;

            int y = str[0] - 'A';
            int x = str[1] - '1';
            sudoku[y][x] = i;
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                todo.push_back({i, j});
            }
        }

        dfs(0);
    }

    return 0;
}