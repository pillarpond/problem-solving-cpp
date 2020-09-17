//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 2000001;

int N;

int arr[20] = {0,};
bool check[MAX] = {0,};

void dfs(int index, int sum) {
    check[sum] = true;

    if (index == N) return;

    dfs(index + 1, sum);
    dfs(index + 1, sum + arr[index]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    dfs(0, 0);

    for (int i = 1; i < MAX; ++i) {
        if (!check[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}