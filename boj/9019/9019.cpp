//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

constexpr int MAX = 10001;

bool visited[MAX] = {0,};
int A, B;

string bfs() {
    queue<pair<int, string> > q;
    q.push({A, ""});
    visited[A] = true;

    while(!q.empty()) {
        int now;
        string cmd;

        tie(now, cmd) = q.front();
        q.pop();

        if (now == B) return cmd;

        int next = now * 2;
        next = next > 9999 ? next % 10000 : next;
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, cmd + "D"});
        }

        next = now == 0 ? 9999 : now - 1;
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, cmd + "S"});
        }

        next = (now - (now / 1000 * 1000)) * 10 + (now / 1000);
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, cmd + "L"});
        }

        next = now / 10 + (now % 10) * 1000;
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, cmd + "R"});
        }
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        cin >> A >> B;

        memset(visited, 0, sizeof(visited));
        cout << bfs() << "\n";
    }

    return 0;
}