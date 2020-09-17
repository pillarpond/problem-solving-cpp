//dfs

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 81;

int N;
vector<int> v;

bool good() {
    int len = v.size();
    
    for(int i = 1; i <= len / 2; ++i){
        string s1 = "";
        string s2 = "";

        for(int j = 0; j < i; ++j){
            s1 += to_string(v[len - (2 * i) + j]);
            s2 += to_string(v[len - i + j]);
        }

        if(s1 == s2) return false;
    }
    return true;
}

void dfs(int len) {
    if (len == N) {
        for (int i = 0; i < N; ++i) cout << v[i];
        cout << "\n";

        exit(0);
    }

    for (int i = 1; i < 4; ++i) {
        v.push_back(i);
        if (good()) dfs(len + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N;
    dfs(0);
}