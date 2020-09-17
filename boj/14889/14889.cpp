//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 20;

int N;

int S[MAX][MAX] = {0,};

vector<int> start;
vector<int> link;

int diff = 987654321;

int getdiff() {
    int sum = 0;

    for (int i : start) {
        for (int j : start) {
            sum += S[i][j];
        }
    }

    for (int i : link) {
        for (int j : link) {
            sum -= S[i][j];
        }
    }

    return abs(sum);
}

void dfs(int index) {
    if (index == N) {
        diff = min(diff, getdiff());
        return;
    }

    if (start.size() < N /2) {
        start.push_back(index);
        dfs(index + 1);
        start.pop_back();
    }

    if (link.size() < N /2) {
        link.push_back(index);
        dfs(index + 1);
        link.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }

    dfs(0);
    cout << diff << "\n";
    return 0;
}