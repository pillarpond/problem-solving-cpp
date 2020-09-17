//sieve

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

constexpr int MAX = 4000001;

bool prime[MAX] = {0,};

vector<int> v;

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        for (int j = i + i; j < MAX; j += i) {
            prime[j] = false;
        }
    }

    for (int i = 2; i < MAX; ++i) {
        if (prime[i]) v.push_back(i);
    }
}

int dfs(int num, int idx) {
    if (num == 0) return 1;
    if (idx > v.size()) return 0;

    if (num >= v[idx]) return dfs(num - v[idx], idx + 1);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        cnt += dfs(N, i);
    }

    cout << cnt << "\n";
    return 0;
}