//dfs

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int arr[13] = {0,};
bool visited[13] = {0,};
vector<int> v;

void dfs(int index) {
    if (v.size() == 6) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = index; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(arr[i]);
            dfs(i + 1);
            v.pop_back();
            visited[i] = false;
        } else {
            dfs(i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        memset(visited, 0, sizeof(visited));
        dfs(0);
        cout << "\n";
    }
    return 0;
}