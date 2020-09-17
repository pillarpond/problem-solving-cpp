//mst

#include <iostream>
#include <vector>
#include <algorithm>
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<tuple<int,int,int> > graph(E);
    parents.resize(V + 1);

    for (int i = 0; i <= V; ++i) parents[i] = i;

    for (int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        graph[i] = {C, A, B};
    }

    sort(graph.begin(), graph.end());

    int sum = 0;
    for (int i = 0; i < E; ++i) {
        int cost, from, to;
        tie(cost, from, to) = graph[i];

        if (find(from) != find(to)) {
            unite(from, to);
            sum += cost;
        }
    }

    cout << sum << "\n";
    return 0;
}