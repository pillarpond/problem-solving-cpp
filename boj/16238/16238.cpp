//greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<int>());

    int sum = 0, day = 0;
    for (int a : A) {
        if (day > a) break;
        sum += a - day;
        ++day;
    }

    cout << sum << "\n";
    return 0;
}