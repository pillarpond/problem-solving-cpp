//geom

#include <iostream>

using namespace std;

int main() {
    auto x = 0, y = 0, w = 0, h = 0;
    cin >> x >> y >> w >> h;

    auto min_w = min(x, w - x);
    auto min_h = min(y, h - y);

    cout << min(min_w, min_h) << endl;
    return 0;
}