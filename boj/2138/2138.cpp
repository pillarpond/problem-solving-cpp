//greedy

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX = 100001;

char arr[MAX] = {0,};
int N;

bool diff[MAX] = {0,};
bool tmp[MAX] = {0,};

void reverse(int n) {
    if (n != 0) tmp[n - 1] = !tmp[n - 1];
    tmp[n] = !tmp[n];
    if (n != N - 1) tmp[n + 1] = !tmp[n + 1];
}

int greedy(bool b) {
    int cnt = 0;
    memcpy(tmp, diff, sizeof(diff));

    if (b) {
        ++cnt;
        reverse(0);
    }

    for (int i = 1; i < N; ++i) {
        if (tmp[i - 1]) {
            ++cnt;
            reverse(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (tmp[i]) return 987654321;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;

        diff[i] = (arr[i] != c) ? true : false;
    }

    int ans = min(greedy(true), greedy(false));

    if (ans >= 987654321) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}