//dp

#include <iostream>
using namespace std;

int arr[1001] = {0};
int sum[1001][1001] = {0};

int main() {
    string str1, str2;

    cin >> str1;
    cin >> str2;

    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                sum[i][j] = sum[i - 1][j - 1] + 1;
            } else {
                sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]);
            }
        }
    }

    cout << sum[str1.size()][str2.size()] << endl;
    return 0;
}