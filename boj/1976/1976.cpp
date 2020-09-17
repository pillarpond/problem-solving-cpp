//union find

#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int find(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    parents.resize(N + 1);
    for (int i = 0; i <= N; ++i) parents[i] = i;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int connect;
            cin >> connect;

            if (connect) {
                unite(i, j);
            }
        }
    }

    vector<int> tour(M);
    for (int i = 0; i < M; ++i) {
        cin >> tour[i];
    }

    int check = find(tour[0]);
    for (int i = 1; i < M; ++i) {
        if (check != find(tour[i])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}