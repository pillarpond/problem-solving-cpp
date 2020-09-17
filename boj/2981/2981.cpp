//math

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[101] = {0};

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    auto N = 0;
    cin >> N;

    vector<int> v(N);
    vector<int> M;

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    auto gcd = v[1] - v[0];

    for (int i = 2; i < N; ++i) {
        gcd = GCD(gcd, v[i] - v[i - 1]);
    }

    for (int i = 2; i * i <= gcd; ++i) {
        if (gcd % i == 0) {
            M.push_back(i);
            M.push_back(gcd / i);
        }
    }

    M.push_back(gcd);
    sort(M.begin(), M.end());
    M.erase(unique(M.begin(), M.end()), M.end());

    for (int i = 0; i < M.size(); ++i) {
        cout << M[i] << " ";
    }
    cout << "\n";

    return 0;
}