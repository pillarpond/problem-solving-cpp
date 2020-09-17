//euler circuit

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 1000;
int graph[MAX + 1][MAX + 1] = {0,};
int degree[MAX + 1] = {0,};
int N;

void dfs(int n) {
    for (int i = 1; i <= N; ++i) {
        while(graph[n][i]) {
            --graph[n][i];
            --graph[i][n];
            dfs(i);
        }
    }

    cout << n << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> graph[i][j];
            degree[i] += graph[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            cout << "-1\n";
            return 0;
        }
    }

    dfs(1);
    cout << "\n";

    return 0;
}