//sweeping

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if (y == v.y) {
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
};

bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}

int dist(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    int n;
    cin >> n;

    vector<Point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end(), cmp);

    int d = dist(v[0], v[1]);
    set<Point> cand;
    cand.insert(v[0]);
    cand.insert(v[1]);

    int start = 0;
    for (int i = 2; i < n; ++i) {
        Point now = v[i];
        while(start < i) {
            Point p = v[start];
            int x = p.x - now.x;

            if (x*x > d) {
                cand.erase(p);
                start++;
            } else {
                break;
            }
        }
        int tmp = (int)sqrt((double)d) + 1;
        auto lp = Point(-100000, now.y - tmp);
        auto up = Point(100000, now.y + tmp);

        auto lower = cand.lower_bound(lp);
        auto upper = cand.upper_bound(up);

        for (auto it = lower; it != upper; ++it) {
            int tmp = dist(now, *it);
            if (tmp < d) {
                d = tmp;
            }
        }
        cand.insert(now);
    }

    cout << d << "\n";
    return 0;
}