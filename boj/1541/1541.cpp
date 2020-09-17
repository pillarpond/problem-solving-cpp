//math

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string eq;
    cin >> eq;

    auto sum = 0, start = 0;
    auto minus = false;

    for (int i = 0; i <= eq.size(); ++i) {
        if (eq[i] == '+' || eq[i] == '-' || i == eq.size()) {

            if (minus) {
                sum -= stoi(eq.substr(start, i));
            } else {
                sum += stoi(eq.substr(start, i));
                if (eq[i] == '-') minus = true;
            }

            start = i + 1;
        }
    }

    cout << sum << endl;
    return 0;
}