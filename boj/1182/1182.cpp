//bfs

#include <iostream>
#include <vector>

using namespace std;

int N, S;
int arr[20] = {0,};
int cnt = 0;

void dfs(int index, int sum) {
    if (index == N) return;

    dfs(index + 1, sum);

    if (sum + arr[index] == S) ++cnt;
    dfs(index + 1, sum + arr[index]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    dfs(0, 0);
    cout << cnt << "\n";

    return 0;
}