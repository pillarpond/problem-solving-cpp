//dp

#include <iostream>
#include <vector>
using namespace std;

unsigned long P[101] = {0};

int main() {
    auto T = 0, max = 0;
    vector<int> v;
    cin >> T;
    for (int i = 0; i < T; i++) {
        auto N = 0;
        cin >> N;
        v.push_back(N);

        if (N > max) max = N;
    }

    P[1] = P[2] = P[3] = 1;
    P[4] = 2;

    for (int i = 5; i <= max; i++) {
        P[i] = P[i - 1] + P[i - 5];
    }

    for (int i = 0; i < T; i++) {
        auto N = v[i];
        cout << P[N] << endl;
    }
    return 0;
}