//bfs

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;

constexpr int MAX = 10000;
int s, g;

bool visited[MAX] = {0,};
bool prime[MAX] = {0,};

int swap(int n, int idx, int r) {
    int nn = 0;
    for (int i = 0; i < 4; ++i) {
        int num;

        if (i == idx) num = r;
        else num = n % 10;

        n /= 10;
        nn += num * (pow(10, i)); 
    }

    return nn;
}

int bfs() {
    queue<pii> q;
    q.push({s, 0});

    memset(visited, 0, sizeof(visited));
    visited[s] = true;

    while(!q.empty()) {
        int n, c;

        tie(n, c) = q.front();
        q.pop();

        if (n == g) return c;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 10; ++j) {
                int nn = swap(n, i, j);

                if (nn >= MAX || nn < 1000) continue;
                if (visited[nn]) continue;
                if (!prime[nn]) continue;

                visited[nn] = true;
                q.push({nn, c + 1});
            }
        }
    }

    return -1;
}

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < 10000; ++i) {
        for (int j = i + i; j < 10000; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    sieve();

    while(T--) {
        cin >> s >> g;
        int ans = bfs();

        if (ans == -1) cout << "Impossible\n";
        else cout << ans << "\n";
    }

    return 0;
}