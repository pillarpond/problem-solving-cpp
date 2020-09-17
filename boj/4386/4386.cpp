//mst

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parents;

int find(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    parents.resize(n);
    for (int i = 0; i < n; ++i) parents[i] = i;

    vector<pair<int,int> > stars(n);
    for (int i = 0; i < n; ++i) {
        float x, y;
        cin >> x >> y;
        stars[i] = {x, y};
    }

    vector<tuple<float,int,int> > lines;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            float dx = pow((stars[i].first - stars[j].first), 2);
            float dy = pow((stars[i].second - stars[j].second), 2);
            float dist = sqrt(dx + dy);

            lines.push_back({dist, i , j});
        }
    }

    sort(lines.begin(), lines.end());
    float sum = 0;

    for(int i = 0; i < lines.size(); ++i) {
        int from, to;
        float dist;
        tie(dist, from, to) = lines[i];

        if (find(from) != find(to)) {
            unite(from, to);
            sum += dist;
        }
    }

    cout << sum << "\n";
    return 0;
}