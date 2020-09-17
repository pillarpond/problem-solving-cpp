//dfs

#include <iostream>

using namespace std;

typedef pair<int,int> pii;

constexpr int MAX = 11;

int arr[MAX][MAX] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

bool visited[MAX][MAX][MAX][MAX] = {0,};

pii goal, red, blue;

void move(pii &ball, int &c, int index) {
    while (arr[ball.second + dy[index]][ball.first + dx[index]] == 1) {
        ball.first += dx[index];
        ball.second += dy[index];
        ++c;

        if (ball == goal) break;
    }
}

bool dfs(int cnt) {
    bool res = false;
    if (cnt > 10) return false;

    pii pred = red, pblue = blue;
    for (int i = 0; i < 4; ++i) {
        pii nred = red, nblue = blue;
        int rc = 0, bc = 0;
    
        move(nred, rc, i);
        move(nblue, bc, i);

        if (nblue == goal) continue;

        if (nred == goal) return true;

        if (nblue == nred) {
            if (bc > rc) {
                nblue.first -= dx[i];
                nblue.second -= dy[i];
            } else {
                nred.first -= dx[i];
                nred.second -= dy[i];
            }
        }

        if (!visited[nred.first][nred.second][nblue.first][nblue.second]) {
            visited[nred.first][nred.second][nblue.first][nblue.second] = true;
            red = nred;
            blue = nblue;
            res |= dfs(cnt + 1);
            blue = pblue;
            red = pred;
            visited[nred.first][nred.second][nblue.first][nblue.second] = false;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j) {
            switch (str[j]) {
                case '.':
                    arr[i][j] = 1;
                    break;
                case 'O':
                    arr[i][j] = 1;
                    goal = {j, i};
                    break;
                case 'R':
                    arr[i][j] = 1;
                    red = {j, i};
                    break;
                case 'B':
                    arr[i][j] = 1;
                    blue = {j, i};
                    break;
            }
        }
    }

    visited[red.first][red.second][blue.first][blue.second] = true;
    bool ans = dfs(1);

    if (ans) cout << "1\n";
    else cout << "0\n";

    return 0;
}