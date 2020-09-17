//tsort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 10;

int indegree_max[MAX] = {0,};
int indegree_min[MAX] = {0,};

int res_max[MAX] = {0,};
int res_min[MAX] = {0,};

vvi graph(MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for(int i = 0; i < k; ++i) {
        char c;
        cin >> c;

        if (c == '>') {
            ++indegree_max[i + 1];
            ++indegree_min[i + 1];

            graph[i].push_back(i + 1);
        } else {
            ++indegree_max[i];
            ++indegree_min[i];
            
            graph[i + 1].push_back(i);
        }
    }

    priority_queue<int, vector<int>, greater<int> > pq_max;
    for (int i = 0; i < k + 1; ++i) {
        if (indegree_max[i] == 0) pq_max.push(i);
    }

    int num = 9;
    for (int i = 0; i < k + 1; ++i) {
        int now = pq_max.top();
        pq_max.pop();

        res_max[now] = num;
        --num;

        for (int next : graph[now]) {
            if (--indegree_max[next] == 0) pq_max.push(next);
        }
    }

    priority_queue<int> pq_min;
    for (int i = 0; i < k + 1; ++i) {
        if (indegree_min[i] == 0) pq_min.push(i);
    }

    num = k;
    for (int i = 0; i < k + 1; ++i) {
        int now = pq_min.top();
        pq_min.pop();

        res_min[now] = num;
        --num;

        for (int next : graph[now]) {
            if (--indegree_min[next] == 0) pq_min.push(next);
        }
    }

    for (int i = 0; i < k + 1; ++i) cout << res_max[i];
    cout << "\n";

    for (int i = 0; i < k + 1; ++i) cout << res_min[i];
    cout << "\n";

    return 0;
}