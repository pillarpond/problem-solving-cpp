//bsearch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;

        vec.push_back(card);
    }

    sort(vec.begin(), vec.end());

    cin >> M;
    
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        bool exists = binary_search(vec.begin(), vec.end(), num);
        cout << exists << " ";
    }
    cout << "\n";

    return 0;
}