// impl

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 500001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    int depth = log2(MAX) + 1;

    vector<vector<long long> > f(m + 1, vector<long long>(depth, 0));
    for (int i = 1; i <= m; ++i) {
        cin >> f[i][0];
    }

    for (int i = 1; i < depth; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a = f[j][i - 1];
            f[j][i] = f[a][i - 1];
        }
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int n, x;
        cin >> n >> x;

        for(int i = 0; n; ++i) {
            if (n & 1) x = f[x][i];
            n >>= 1;
        }
        cout << x << "\n";
    }
    return 0;
}