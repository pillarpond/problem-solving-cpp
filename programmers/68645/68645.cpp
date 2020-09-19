#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX = 1001;

int cnt = 0;
int arr[MAX][MAX] = {0,};

void snail(int x, int y, int n) {
    for (int i = 0; i < n; ++i) arr[y + i][x] = ++cnt;
    for (int i = 1; i < n; ++i) arr[y + n - 1][x + i] = ++cnt;
    for (int i = n - 2; i > 0; --i) arr[y + i][x + i] = ++cnt;
}

vector<int> solution(int n) {
    vector<int> answer;

    int x = 0, y = 0;
    for (int i = n; i > 0; i -= 3) {
        snail(x, y, i);
        ++x;
        y += 2;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}

int main() {
    int n = 6;
    vector<int> answer = solution(n);
    for (int a : answer) cout << a << " ";
    return 0;
}