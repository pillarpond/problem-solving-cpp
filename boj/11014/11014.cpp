//bmatch

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 81;

int arr[MAX][MAX] = {0,};

int visited[MAX * MAX];
int match[MAX * MAX] = {0,};

int dx[] = {-1, -1, -1, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1};

vvi graph;

int dfs(int now) {
    if (visited[now]) return 0;
    visited[now] = true;

    for (int next : graph[now]) {
        if (!match[next] || dfs(match[next])) {
            match[next] = now;
            return 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    cin >> C;

    while(C--) {
        int N, M;
        cin >> N >> M;

        memset(arr, 0, sizeof(arr));
        memset(match, 0, sizeof(match));

        graph.clear();
        graph.resize((N + 1) * (M + 1));

        int sum = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                char c;
                cin >> c;

                arr[i][j] = c == 'x';
                sum += c == '.';
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (arr[i][j]) continue;

                for (int k = 0; k < 6; ++k) {
                    int x = j + dx[k];
                    int y = i + dy[k]; 

                    if (arr[y][x]) continue;
                    if (x < 1 || x > M || y < 1 || y > N) continue;
                    graph[i * M + j].push_back(y * M + x);
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; j += 2) {
                if (arr[i][j]) continue;

                memset(visited, 0, sizeof(visited));
                if (dfs(i * M + j)) ++cnt;
            }
        }

        cout << sum - cnt << "\n";
    }

    return 0;
}