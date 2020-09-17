//math

#include <iostream>

using namespace std;

int main() {
    auto N = 0;
    cin >> N;

    auto line = 0, cnt = 1;

    for (; line < N; ++cnt) {
        line += cnt;
    }

    auto mother = N - line + cnt - 1;
    auto child = line - N + 1;

    if (cnt % 2 == 1) {
        cout << mother << "/" << child << endl;
    } else {
        cout << child << "/" << mother << endl;
    }

    return 0;
}