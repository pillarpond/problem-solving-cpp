//mst

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>

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

    int N, M;
    cin >> N >> M;

    parents.resize(N + 1);
    vector<pair<int,int> > ufo(N + 1);

    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;

        ufo[i] = {x, y};
        parents[i] = i;
    }

    vector<tuple<double,int,int> > lines;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;

            long long dx = pow(ufo[i].first - ufo[j].first, 2);
            long long dy = pow(ufo[i].second - ufo[j].second, 2);
            double dist = sqrt(dx + dy);
            lines.push_back({dist, i, j});
        }
    }

    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        unite(from, to);
    }

    sort(lines.begin(), lines.end());
    double sum = 0;

    for (int i = 0; i < lines.size(); ++i) {
        int from, to;
        double dist;
        tie(dist, from, to) = lines[i];

        if (find(from) != find(to)) {
            unite(from, to);
            sum += dist;
        }
    }

    cout << fixed;
    cout.precision(2);
    
    cout << sum << "\n";
    return 0;
}