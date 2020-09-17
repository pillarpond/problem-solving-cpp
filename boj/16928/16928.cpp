//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int board[101] = {0,};
bool visited[101] = {0,};

int bfs() {
    queue<pair<int,int> > q;
    q.push({board[1], 0});
    visited[1] = visited[board[1]] = true;

    while(!q.empty()) {
        int now, cnt;
        tie(now, cnt) = q.front();
        q.pop();

        if (now == 100) return cnt;

        for (int i = 1; i <= 6; ++i) {
            int next = now + i;
            if (next > 100) break;

            if (!visited[next] && !visited[board[next]]) {
                visited[next] = visited[board[next]] = true;
                q.push({board[next], cnt + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 100; ++i) board[i] = i;

    cin >> N >> M;
    int cnt = N + M;

    while(cnt--) {
        int idx, num;

        cin >> idx >> num;
        board[idx] = num;
    }

    cout << bfs() << "\n";
    return 0;
}