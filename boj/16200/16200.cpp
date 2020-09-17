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

    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());
    
    int cnt = 1;
    int group = 0;
    int th = 0;

    for (int x : X) {
        if (cnt == 1) {
            ++group;
            th = x;
        }

        if (cnt >= th) cnt = 1;
        else ++cnt;
    }

    cout << group << "\n";
    return 0;
}