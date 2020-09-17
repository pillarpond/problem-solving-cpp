//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int,int> pii;

constexpr int MAX = 501;

int A, B, C;
int sum;

bool visited[MAX][MAX] = {0,};

void calc(int &x, int &y) {
    if (x > y) {
        x -= y;
        y += y;
    } else if (y > x) {
        y -= x;
        x += x;
    }
}

int bfs() {
    queue<pii> q;
    q.push({A, B});
    visited[A][B] = true;

    while(!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        int c = sum - a - b;

        if (a == b && b == c) return 1;

        int dx[3] = {a, a, b};
        int dy[3] = {b, c, c};

        for (int i = 0; i < 3; ++i) {
            int x = dx[i];
            int y = dy[i];
            int z = sum - x - y;
            calc(x, y);

            int nx = min(x, min(y, z));
            int ny = max(x, max(y, z));

            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;
    sum = A + B + C;

    if (sum % 3 != 0) cout << "0\n";
    else cout << bfs() << "\n";

    return 0;
}