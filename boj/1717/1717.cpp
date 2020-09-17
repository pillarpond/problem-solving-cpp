//union find

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i) parent[i] = i; 

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a) {
            if (find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            unite(b, c);
        }
    }
    return 0;
}