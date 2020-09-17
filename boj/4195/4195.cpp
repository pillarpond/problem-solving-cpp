//union find

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> parents;
vector<int> friends;
map<string,int> m;

int find(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        parents[x] = y;
        friends[y] += friends[x];
        friends[x] = 1;
    }

    return friends[y];
}

void add(string name) {
    const auto it = m.find(name);
    if (it == m.end()) {
        int num = m.size();
        m[name] = num;

        parents.push_back(num);
        friends.push_back(1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int F;
        cin >> F;

        parents.clear();
        friends.clear();
        m.clear();

        for (int i = 0; i < F; ++i) {
            string name1, name2;
            cin >> name1 >> name2;

            add(name1);
            add(name2);

            cout << unite(m[name1], m[name2]) << "\n";
        }
    }

    return 0;
}