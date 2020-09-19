#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX = 1000001;

int leftmin[MAX] = {0,};
int rightmin[MAX] = {0,};

int solution(vector<int> a) {
    if (a.size() <= 2) return a.size();

    int answer = 2;
    int last = a.size() - 1;

    leftmin[0] = a[0];
    rightmin[last] = a[last];

    for (int i = 1; i <= last; ++i) leftmin[i] = min(a[i], leftmin[i - 1]);
    for (int i = last - 1; i >= 0; --i) rightmin[i] = min(a[i], rightmin[i + 1]);

    for (int i = 1; i < last; ++i) {
        if (leftmin[i] == a[i] || rightmin[i] == a[i]) ++answer;
    }

    return answer;
}

int main() {
    vector<int> a = {9, -1, -5};
    int answer = solution(a);
    cout << answer;
    return 0;
}