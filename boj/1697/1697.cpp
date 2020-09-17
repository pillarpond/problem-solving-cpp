//bfs

#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100000;
bool visited[MAX + 1] = {0,};

bool check(int n) {
    if (n >= 0 && n <= MAX && !visited[n]) {
        visited[n] = true;
        return true;
    }
    return false;
}

int bfs(queue<pair<int,int> > &q, int K) {
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if (p.first == K) return p.second;
        int day = p.second + 1;

        int n = p.first - 1;
        if (check(n)) q.push(make_pair(n, day));

        n = p.first + 1;
        if (check(n)) q.push(make_pair(n, day));

        n = p.first * 2;
        if (check(n)) q.push(make_pair(n, day));
    }
    return -1;
}

int main(){
    int N, K;
    cin >> N >> K;

    queue<pair<int,int> > q;
    visited[N] = true;
    q.push(make_pair(N,0));

    cout << bfs(q, K) << "\n";
    return 0;
}