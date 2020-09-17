//greedy

#include <iostream>

using namespace std;

int N, M, K;

int greedy() {
    int team = min(N / 2, M);
    int intern = N - (team * 2) + M - team;

    while(intern < K) {
        --team;
        intern += 3;
    }

    return team;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    cout << greedy() << "\n";
    return 0;
}