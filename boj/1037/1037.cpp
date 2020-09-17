//math

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, num = 0;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cout << v.front() * v.back() << endl;
    return 0;
}