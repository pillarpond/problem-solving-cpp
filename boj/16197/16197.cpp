//dfs

#include <iostream>
#include <tuple>

using namespace std;

constexpr int MAX = 20;
typedef pair<int,int> pii;

int N, M;
bool wall[MAX][MAX] = {0,};

pii coin1 = {-1, -1};
pii coin2 = {-1, -1};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(pii coin) {
    if (coin.first < 0 || coin.first >= M) return true;
    if (coin.second < 0 || coin.second >= N) return true;
    return false;
}

void move(int x, int y) {
    if (!wall[coin1.second + y][coin1.first + x]) {
        coin1.first += x;
        coin1.second += y;
    }

    if (!wall[coin2.second + y][coin2.first + x]) {
        coin2.first += x;
        coin2.second += y;
    }
}

int dfs(int cnt) {
    if (cnt > 10) return 11;
    if (check(coin1) && check(coin2)) return 11;
    if (check(coin1) != check(coin2)) return cnt;

    int res = 11;
    pii pcoin1 = coin1, pcoin2 = coin2;

    for (int i = 0; i < 4; ++i) {
        move(dx[i], dy[i]);
        res = min(res, dfs(cnt + 1));
        coin1 = pcoin1;
        coin2 = pcoin2;
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
                case '#':
                    wall[i][j] = true;
                    break;
                case 'o':
                    if (coin1.first == -1) {
                        coin1.first = j;
                        coin1.second = i;
                    } else {
                        coin2.first = j;
                        coin2.second = i;
                    }
                    break;
            }
        }
    }


    int ans = dfs(0) > 10 ? -1 : dfs(0);
    cout << ans << "\n";
    return 0;
}