//dp

#include <iostream>
#include <vector>
using namespace std;

unsigned long zero[41] = {0};
unsigned long one[41] = {0};

int main() {
    int T = 0;
    cin >> T;

    vector<int> v;

    for (int i = 0; i < T; i++) {
        auto N = 0;
        cin >> N;
        v.push_back(N);
    }

    for (int i = 0; i < T; i++) {
        auto N = v[i];

        zero[0] = 1;
        one[1] = 1;
        for (int i = 2; i <= N; i++) {
            zero[i] = zero[i - 1] + zero[i - 2];
            one[i] = one[i - 1] + one[i - 2];
        }

        cout << zero[N] << " " << one[N] << endl;
    }
    return 0;
}