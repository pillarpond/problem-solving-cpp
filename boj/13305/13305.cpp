//greedy

#include <iostream>

using namespace std;

constexpr int MAX = 100001;

int dist[MAX] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        cin >> dist[i];
    }

    long long ans = 0;
    int sum = 0;
    long long now = 1000000001;

    for (int i = 0; i < N - 1; ++i) {
        int num;
        cin >> num;

        if (num < now) {
            ans += now * sum;
            now = num;
            sum = dist[i];
        } else {
            sum += dist[i];
        }
    }

    ans += now * sum;
    cout << ans << "\n";

    return 0;
}