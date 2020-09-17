//geom

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        set<int> sx, sy;
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;

            sx.insert(x);
            sy.insert(y);
        }

        if (sx.size() * sy.size() == N) cout << "BALANCED\n";
        else cout << "NOT BALANCED\n";
    }
    return 0;
}