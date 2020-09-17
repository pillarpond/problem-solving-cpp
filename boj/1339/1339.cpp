//dfs

#include <iostream>
#include <vector>

using namespace std;

int N;
char numalp[10];
int alpnum[10];
bool visited[10];

int cnt = 0;
long long sum = 0;

vector<string> str(10);

int find(char c) {
    for (int i = 0; i < 10; ++i) {
        if (numalp[i] == c) return i;
    }

    return -1;
}

long long getsum() {
    long long s = 0;

    for (int i = 0; i < N; ++i) {
        long long n = alpnum[find(str[i][0])];
        for (int j = 1; j < str[i].size(); ++j) {
            n *= 10;
            n += alpnum[find(str[i][j])];
        }
        s += n;
    }
    return s;
}

void dfs(int index) {
    if (index == cnt) {
        sum = max(sum, getsum());
        return;
    }

    for (int i = 9; i >= 0; --i) {
        if (visited[i]) continue;
        visited[i] = true;
        alpnum[index] = i;
        dfs(index + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> str[i];

        for (int j = 0; j < str[i].size(); ++j) {
            if (find(str[i][j]) == -1) {
                numalp[cnt] = str[i][j];
                ++cnt;
            }
        }
    }

    dfs(0);
    cout << sum << "\n";

    return 0;
}