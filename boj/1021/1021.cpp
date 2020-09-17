//deque

#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
	cin.sync_with_stdio(false);

    auto N = 0, M = 0;
    cin >> N >> M;


    deque<int> dq;
    deque<int>::iterator lit;
    deque<int>::iterator rit;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    auto num = 0, cnt = 0;
    for (int i = 0; i < M; ++i) {
        cin >> num;

        if (dq.front() == num) {
            dq.pop_front();
        } else {
            lit = dq.begin();
            rit = dq.end() - 1;

            for (int j = 0; j < dq.size(); ++j) {
                if (*lit == num) {
                    for (int k = 0; k < j; ++k) {
                        dq.push_back(dq.front());
                        dq.pop_front();
                    }
                    cnt += j;
                    dq.pop_front();
                    break;
                } else if (*rit == num) {
                    for (int k = 0; k < j; ++k) {
                        dq.push_front(dq.back());
                        dq.pop_back();
                    }
                    cnt += j + 1;
                    dq.pop_back();
                    break;
                }
                lit++;
                rit--;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}