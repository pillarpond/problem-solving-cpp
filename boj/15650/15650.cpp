//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 9;

vector<int> v;

bool visited[MAX] = {0,};
int N, M;

void dfs(int index, int cnt) {
    if (cnt == M) {
        for (int val : v) cout << val << " ";
        cout << "\n";
    }

    for (int i = index; i <= N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i, cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}