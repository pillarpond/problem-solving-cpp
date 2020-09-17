//impl

#include <iostream>

using namespace std;

int k(int n) {
    int m1 = 1, m2 = 1, period = 0;
    
    do {
        int tmp = m1;
        m1 = m2;
        m2 = (tmp + m2) % n;
        period++;
    } while(m1 != 1 || m2 != 1);

    return period;
}

int main() {
    int P;
    cin >> P;

    for (int i = 0; i < P; ++i) {
        int N, M;
        cin >> N >> M;

        cout << N << " " << k(M) << "\n";
    }

    return 0;
}