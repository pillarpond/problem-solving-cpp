//impl

#include <iostream>

using namespace std;

int main() {
    int x[3] = {0}, y[3] = {0};
    
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    auto px = x[0], py = y[0];

    if (x[1] != x[2]) {
        px = x[0] == x[2] ? x[1] : x[2];
    }

    if (y[1] != y[2]) {
        py = y[0] == y[2] ? y[1] : y[2];
    }

    cout << px << " " << py << endl;
    return 0;
}