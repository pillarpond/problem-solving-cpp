//sieve

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 2001;
constexpr int MAX_N = 51;

bool prime[MAX];

bool visited[MAX_N] = {0,};
int arr[MAX_N] = {0,};
int match[MAX_N] = {0,};

vvi graph;

int N;

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

    cin >> N;

    graph.resize(N + 1);
    memset(prime, 1, sizeof(prime));

    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j < MAX; j += i) {
            prime[j] = false;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;
            if (prime[arr[i] + arr[j]]) {
                graph[i].push_back(j);
            }
        }
    }

    vi ans;
    for (int i : graph[1]) {
        memset(match, 0, sizeof(match));

        int flow = 1;
        match[i] = 1;
        
        for (int j = 2; j <= N; ++j) {
            memset(visited, 0, sizeof(visited));
            visited[1] = true;
            flow += dfs(j);
        }

        if (flow == N) ans.push_back(arr[i]);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) cout << "-1\n";
    else {
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}