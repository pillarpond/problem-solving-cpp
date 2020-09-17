//dfs

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int index, int cnt) {
    if (cnt == M) {
        for (int val : v) cout << val << " ";
        cout << "\n";
        return;
    }

    for (int i = index; i <= N; ++i) {
        v.push_back(i);
        dfs(i, cnt + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dfs(1, 0);
    return 0;
}