//bmatch

#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int,int> shark;

constexpr int MAX = 51;

bool visited[MAX];
int match[MAX];

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
    vector<shark> sharks(N + 1);

    for (int i = 1; i <= N; ++i) {
        int size, speed, brain;
        cin >> size >> speed >> brain;
        sharks[i] = {size, speed, brain};
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;

            int a_size, a_speed, a_brain;
            int b_size, b_speed, b_brain;

            tie(a_size, a_speed, a_brain) = sharks[i];
            tie(b_size, b_speed, b_brain) = sharks[j];
            if (a_size == b_size && a_speed == b_speed && a_brain == b_brain) {
                if (i > j) graph[i].push_back(j);
            } else if (a_size >= b_size && a_speed >= b_speed && a_brain >= b_brain) {
                graph[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 2; ++j) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) ++cnt;
        }
    }

    cout << N - cnt << "\n";
    return 0;
}