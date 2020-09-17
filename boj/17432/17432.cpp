//sort

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<int> a(n, 0);
        int s = 1;
        int e = n - 1;

        while (m > e) {
            m -= e;
            a[e] = s++;
            --e;
        }

        a[m] = s++;

        for (int i = 0; i < n; ++i) {
            if (s > n) break;

            if (a[i] == 0) {
                a[i] = s++;
            }
        }

        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}