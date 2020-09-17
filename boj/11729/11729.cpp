//recursion

#include <iostream>
#include <stack>

using namespace std;

void hanoi(int n, int from, int to, int by) {
    if (n == 1) {
        cout << from << " " << to << "\n";
    } else {
        hanoi(n - 1, from, by, to);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, to, from);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 3, 2);
    return 0;
}