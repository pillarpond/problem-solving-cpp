//greedy

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int sum = E + D + C;

    A = max(0, A - D);
    int diff = C - B;
    if (diff > 0) {
        A = max(0, A - diff * 2);
    } else {
        sum += (-diff) / 2 + (-diff) % 2;
        A = max(0, A + diff / 2 + diff % 2 * 3);
    }

    sum += A / 5;
    if (A % 5) sum++;

    cout << sum << "\n";

    return 0;
}