//brute force

#include <iostream>

using namespace std;

int E, S, M;

int main() {
    cin >> E >> S >> M;

    int year = 0;
    int e = 0, s = 0, m = 0;

    while(1) {
        if (e == E && s == S && m == M) break;

        ++e;
        ++s;
        ++m;

        if (e == 16) e = 1;
        if (s == 29) s = 1;
        if (m == 20) m = 1;

        ++year;
    }

    cout << year << "\n";
    return 0;
}