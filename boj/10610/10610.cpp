//sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool zero = false;

vector<int> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int mod = 0;

    for (int i = 0; i < str.size(); ++i) {
        int n = str[i] - '0';
        if (n == 0) zero = true;
        mod += n % 3;

        vec.push_back(n);
    }

    if (!zero || (mod % 3 != 0)) {
        cout << "-1\n";
        return 0;
    }

    sort(vec.begin(), vec.end(), greater<int>());

    for (int v : vec) cout << v;
    cout << "\n";

    return 0;
}