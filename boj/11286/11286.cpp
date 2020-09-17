//prio queue

#include <iostream>
#include <queue>

using namespace std;

struct cmp {
public:
    bool operator()(long long x, long long y) {
        if ((x*x) == (y*y)) return x > y;
        return (x*x) > (y*y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num;
    priority_queue<int,vector<int>,cmp> pq;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }

    return 0;
}