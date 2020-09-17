//sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 51;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i] * B[i];
    }

    cout << sum << "\n";
    return 0;
}