//math

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

string check(int a, int b, int c) {
    if (pow(a,2) == pow(b,2) + pow(c,2)) return "right";
    else return "wrong";
}

int main() {
    auto a = 0, b = 0, c = 0;
    queue<string> q;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;

        if (a > b) {
            if (a > c) {
                q.push(check(a, b, c));
            } else {
                q.push(check(c, a, b));
            }
        } else {
            if (b > c) {
                q.push(check(b, a, c));
            } else {
                q.push(check(c, a, b));
            }
        }
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}