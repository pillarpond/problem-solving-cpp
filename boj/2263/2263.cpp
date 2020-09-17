//tree, dnc

#include <iostream>
#include <vector>

using namespace std;

vector<int> idx;
vector<int> postorder;
vector<int> inorder;

void dnc(int instart, int inend, int poststart, int postend) {
    if (instart > inend || poststart > postend) return;

    int root = postorder[postend];
    cout << root << " ";
    int leftsize = idx[root] - instart;

    dnc(instart, idx[root] - 1, poststart, poststart + leftsize - 1);
    dnc(idx[root] + 1, inend, poststart + leftsize, postend - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    idx.resize(n + 1);
    postorder.resize(n + 1);
    inorder.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> postorder[i];
    }

    dnc(1, n, 1, n);
}