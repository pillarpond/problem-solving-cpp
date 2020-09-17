//dfs

#include <iostream>
#include <vector>

using namespace std;

int N, K;
int ans;
bool visited[26] = {0,};

vector<string> vec;

bool check(const string &str) {
    for (int i = 0; i < str.size(); ++i) {
        if (!visited[str[i] - 'a']) return false;
    }
    return true;
}

void dfs(int index, int remain) {
    if (remain == 0) {
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (check(vec[i])) ++res;
        }
        ans = max(ans, res);
    }

    for (int i = index; i < 26; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, remain - 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    if (K < 5) {
        cout << "0\n";
        return 0;
    }

    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    dfs(0, K - 5);
    cout << ans << "\n";

    return 0;
}