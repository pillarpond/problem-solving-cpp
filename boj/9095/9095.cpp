//dfs

#include <iostream>

using namespace std;

int dfs(int n) {
    if (n == 0) return 1;
    int cnt = 0;

    if (n > 2) cnt += dfs(n - 3);
    if (n > 1) cnt += dfs(n - 2);
    cnt += dfs(n - 1);

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        cout << dfs(n) << "\n";
    }

    return 0;
}