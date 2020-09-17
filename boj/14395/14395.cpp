//bfs

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,string> pls;

set<long long> visited;
int s, t;

string bfs() {
    if (s == t) return "0";

    queue<pls> q;
    q.push({s, ""});
    visited.insert(s);

    while(!q.empty()) {
        long long n;
        string str;

        tie(n, str) = q.front();
        q.pop();

        if (n == t) return str;

        if (n == 0) continue;

        if (visited.find(n * n) == visited.end()) {
            visited.insert(n * n);
            q.push({n * n, str + '*'});
        }
        if (visited.find(n + n) == visited.end()) {
            visited.insert(n + n);
            q.push({n + n, str + '+'});
        }
        if (visited.find(n - n) == visited.end()) {
            visited.insert(n - n);
            q.push({n - n, str + '-'});
        }
        if (visited.find(n / n) == visited.end()) {
            visited.insert(n / n);
            q.push({n / n, str + '/'});
        }
    }

    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    cout << bfs() << "\n";

    return 0;
}