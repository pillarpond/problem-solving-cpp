//dfs

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int sudoku[9][9] = {0,};
vector<pair<int,int> > todo;

void print() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

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

void dfs(int index) {
    if (index == todo.size()) {
        print();
        exit(0);
    }

    int r, c;
    tie(r, c) = todo[index];

    for (int i = 1; i <= 9; ++i) {
        if (check(r, c, i)) {
            sudoku[r][c] = i;
            dfs(index + 1);
            sudoku[r][c] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) todo.push_back({i, j});
        }
    }

    dfs(0);

    return 0;
}