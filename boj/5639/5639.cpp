//dnc

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void dnc(int start, int end) {
    if (start >= end) return;

    auto bound = upper_bound(v.begin() + start + 1, v.begin() + end, v[start]);
    int dist = distance(v.begin(), bound);

    dnc(start + 1 , dist);
    dnc(dist, end);
    cout << v[start] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 0;
    while (cin >> num) {
        v.push_back(num);
    }

    dnc(0, v.size());

    return 0;
}