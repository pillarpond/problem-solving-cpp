//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 9;

int N, M;

bool visited[MAX] = {0,};
vector<int> v;

void dfs(int cnt) {
    if (cnt == M) {
        for (int val : v) cout << val << " ";
        cout << "\n";
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dfs(0);
    return 0;
}