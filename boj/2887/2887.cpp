//mst

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

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

    int N;
    cin >> N;

    parents.resize(N);
    for (int i = 0; i < N; ++i) parents[i] = i;

    vector<pair<int,int> > starx(N);
    vector<pair<int,int> > stary(N);
    vector<pair<int,int> > starz(N);

    for (int i = 0; i < N; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        starx[i] = {x, i};
        stary[i] = {y, i};
        starz[i] = {z, i};
    }

    sort(starx.begin(), starx.end());
    sort(stary.begin(), stary.end());
    sort(starz.begin(), starz.end());

    vector<tuple<int,int,int> > lines;
    for (int i = 0; i < N - 1; ++i) {
        int cost = starx[i + 1].first - starx[i].first;
        lines.push_back({cost, starx[i].second, starx[i + 1].second});

        cost = stary[i + 1].first - stary[i].first;
        lines.push_back({cost, stary[i].second, stary[i + 1].second});

        cost = starz[i + 1].first - starz[i].first;
        lines.push_back({cost, starz[i].second, starz[i + 1].second});
    }

    sort(lines.begin(), lines.end());

    int sum = 0;
    for (int i = 0; i < lines.size(); ++i) {
        int dist, from, to;
        tie(dist, from, to) = lines[i];

        if(find(from) != find(to)) {
            unite(from, to);
            sum += dist;
        }
    }

    cout << sum << "\n";
    return 0;
}