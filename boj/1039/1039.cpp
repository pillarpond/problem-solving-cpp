//bfs

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int,int> pii;

constexpr int MAX = 1000001;

int N, K, len;

bool visited[MAX][11] = {0,};

int swap(int n, int from, int to) {
    string s = to_string(n);
    if (from == 0 && s[to] == '0') return -1;

    swap(s[from], s[to]);
    return atoi(s.c_str());
}

int bfs() {
    queue<pii> q;
    q.push({N, 0});

    while(!q.empty()) {
        int n, c;
        tie(n, c) = q.front();
 
        if (c == K) break;
        q.pop();

        for (int i = 0; i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int nn = swap(n, i, j);

                if (nn == -1) continue;
                if (visited[nn][c + 1]) continue;

                visited[nn][c + 1] = true;
                q.push({nn, c + 1});
            }
        }
    }

    int res = -1;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();

        res = max(res, p.first);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    len = to_string(N).length();

    cout << bfs() << "\n";
    return 0;
}