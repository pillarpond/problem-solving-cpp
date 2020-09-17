//dp

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 2001;

int N, M;
int arr[MAX] = {0,};
int dp[MAX][MAX] = {0,};

int palindrome(int s, int e) {
    int &ret = dp[s][e];
    if (ret != -1) return ret;

    while(s < e) {
        if (arr[s] != arr[e]) return ret = 0;
        ++s;
        --e;
    }

    return ret = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int S, E;
        cin >> S >> E;

        cout << palindrome(S - 1, E - 1) << "\n";
    }
    return 0;
}