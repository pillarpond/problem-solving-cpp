//tree

#include <iostream>
#include <vector>

using namespace std;

void inorder(int node, const vector<vector<int> > &tree) {
    if (node == -1) return;

    inorder(tree[node][0], tree);
    cout << char(node + 'A');
    inorder(tree[node][1], tree);
}

void preorder(int node, const vector<vector<int> > &tree) {
    if (node == -1) return;

    cout << char(node + 'A');
    preorder(tree[node][0], tree);
    preorder(tree[node][1], tree);
}

void postorder(int node, const vector<vector<int> > &tree) {
    if (node == -1) return;

    postorder(tree[node][0], tree);
    postorder(tree[node][1], tree);
    cout << char(node + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > tree(N, vector<int>(2, -1));
    for (int i = 0; i < N; ++i) {
        char a, b, c;
        cin >> a >> b >> c;

        tree[a - 'A'][0] = (b == '.') ? -1 : b - 'A';
        tree[a - 'A'][1] = (c == '.') ? -1 : c - 'A';
    }

    preorder(0, tree);
    cout << "\n";
    inorder(0, tree);
    cout << "\n";
    postorder(0, tree);
    cout << "\n";

    return 0;
}