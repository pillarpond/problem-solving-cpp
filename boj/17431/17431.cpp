//math

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 333333;

string print(int n, int m, char c) {
    char nc = c == 'B' ? 'R' : 'B';
    if (m == 1) return string(n - 1, c);
    return print(m, n % m, nc) + string(n / m, c);
}

int game(int n, int m) {
    if (m == 0) return INF;
    if (m == 1) return n - 1;

    return game(m, n % m) + n / m;
}

string game(int n) {
    int ans = INF;
    int num = 1;
    
    for (int i = 2; i <= n / 2; ++i) {
        int res = game(n , i);

        if (ans > res) {
            ans = res;
            num = i;
        }
    }

    return print(n, num, 'B');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int x;
        cin >> x;

        cout << game(x) << "\n";
    }
    return 0;
}