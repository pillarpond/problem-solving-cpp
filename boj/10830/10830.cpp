//math

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > z;

vector<vector<int> > matmul(vector<vector<int> > &v1, vector<vector<int> > &v2) {
    int n = v1.size();
    vector<vector<int> > v(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                v[i][j] += v1[i][k] * v2[k][j];
            }
            v[i][j] %= 1000;
        }
    }
    return v;
}

vector<vector<int> > matpow(vector<vector<int> > &v, long long b) {
    if (b == 0) return z;
    if (b == 1) return v;
    if (b % 2 == 0) {
        vector<vector<int> > t = matpow(v, b / 2);
        return matmul(t, t);
    } else {
        vector<vector<int> > t = matpow(v, b - 1);
        return matmul(t, v);
    }
}

int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<int> > v(N, vector<int>(N));
    z.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
            z[i][j] = 1;
        }
    }

    vector<vector<int> > r = matpow(v, B);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << r[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
    return 0;
}