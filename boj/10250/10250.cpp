//math

#include <iostream>
#include <queue>

using namespace std;

int main() {
    auto T = 0;
    cin >> T;

    queue<int> q;

    auto H = 0, W = 0, N = 0;
    for (int i = 0; i < T; ++i) {
        cin >> H >> W >> N;
        if (N % H) {
            q.push((N % H) * 100 + N / H + 1);
        } else {
            q.push(H * 100 + N / H);
        }
    }

    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}