//segtree

#include <iostream>
#include <vector>

using namespace std;

int init(vector<int>& v, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = v[start];
    }

    return tree[node] = init(v, tree, node*2, start, (start+end)/2) + init(v, tree, node*2+1, (start+end)/2+1, end);
}

int sum(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];

    return sum(tree, node*2, start, (start+end)/2, left, right) 
    + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    vector<int> tree(N*4);
    int num;

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    init(v, tree, 1, 0, N-1);
    int left, right;

    while(M--) {
        cin >> left >> right;
        cout << sum(tree, 1, 0, N-1, left-1, right-1) << "\n";
    }
    return 0;
}