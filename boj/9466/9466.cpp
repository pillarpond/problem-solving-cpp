//dfs

#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAX = 100001;

int cnt = 0;
int arr[MAX] = {0,};

bool visited[MAX] = {0,};
bool finished[MAX] = {0,};

void dfs(int now) {
    visited[now] = true;

    int next = arr[now];
    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        for (int i = next; ; i = arr[i]) {
            ++cnt;
            if (i == now) break;
        }
    }

    finished[now] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        cnt = 0;

        for (int i = 1; i <= N; ++i) cin >> arr[i];

        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) dfs(i);
        }

        cout << N - cnt << "\n";
    }
    return 0;
}
