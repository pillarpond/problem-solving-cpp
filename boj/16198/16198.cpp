//dfs

#include <iostream>

using namespace std;

constexpr int MAX = 1001;

int N;
int W[MAX] = {0,};
bool visited[MAX] = {0,};

long long dfs(int cnt, long long sum) {
    if (cnt == N - 2) return sum;

    long long res = 0;
    for (int i = 1; i < N - 1; ++i) {

        if (!visited[i]) {
            int prev = -1, next = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (!visited[j]) {
                    prev = j;
                    break;
                }
            }

            for (int j = i + 1; j < N; ++j) {
                if (!visited[j]) {
                    next = j;
                    break;
                }
            }

            if (prev != -1 && next != -1) {
                visited[i] = true;
                res = max(res, dfs(cnt + 1, sum + W[prev] * W[next]));
                visited[i] = false;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}