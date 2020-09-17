//geom

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int T = 0;
    cin >> T;

    int x1, y1, r1, x2, y2, r2; 
    long long d, diff, sum;
    queue<int> q;

    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        diff = pow(r1 - r2, 2);
        sum = pow(r1 + r2, 2);

        if (d == 0 && r1 == r2) q.push(-1);
        else if (d > diff && d < sum) q.push(2);
        else if (d == sum || (d == diff && d != 0)) q.push(1);
        else q.push(0);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}