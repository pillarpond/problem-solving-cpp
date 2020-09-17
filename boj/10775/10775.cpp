//union find

#include <iostream>
#include <vector>

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

    int G, P;
    cin >> G >> P;

    int cnt = 0;
    parents.resize(G + 1);
    for (int i = 0; i <= G; ++i) parents[i] = i;

    for (int i = 0; i < P; ++i) {
        int g;
        cin >> g;

        int parent = find(g);
        if (parent == 0) break;

        unite(parent, parent - 1);
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}