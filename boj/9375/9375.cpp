//impl

#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto n = 0;
    cin >> n;

    auto num = 0;
    string name, type;

    vector<pair<string, int> > v;
    bool check;

    for (int i = 0; i < n; ++i) {
        cin >> num;

        for (int j = 0; j < num; ++j) {
            cin >> name >> type;
            check = false;

            for (int k = 0; k < v.size(); ++k) {
                if (v[k].first == type) {
                    v[k].second++;
                    check = true;
                    break;
                }
            }

            if (!check) {
                v.push_back(make_pair(type, 1));
            }
        }

        auto sum = 1;
        for (int i = 0; i < v.size(); ++i) {
            sum *= v[i].second + 1;
        }

        cout << sum - 1 << endl;
        v.clear();
    }
    return 0;
}