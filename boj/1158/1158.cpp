//queue

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) q.push(i);

    cout << "<";
    while(1) {
        for (int i = 0; i < K - 1; ++i) {
            int top = q.front();
            q.pop();
            q.push(top);
        }
        
        cout << q.front();
        q.pop();

        if (!q.empty()) cout << ", ";
        else break;
    }
    cout << ">\n";

    return 0;
}