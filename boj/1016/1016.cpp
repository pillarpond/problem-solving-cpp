//math

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 1000001;

bool visited[MAX] = {0,};
vector<long long> squre;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long s, e;
    cin >> s >> e;

    long long cnt = 0;

    for (long long i = 2; i <= sqrt(e); ++i) {
        squre.push_back(i * i);
    }

    for (long long sq : squre) {
        long long start = s / sq;
        if (s % sq) ++start;
        start *= sq;

        for (long long i = start; i <= e; i += sq) {
            if (visited[i - s]) continue;

            visited[i - s] = true;
            ++cnt;
        }
    }

    cout << e - s + 1 - cnt << "\n";
    return 0;
}