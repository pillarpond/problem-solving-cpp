#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;

    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(s.begin(), s.end());
    return answer;
}

int main() {
    vector<int> numbers = {2, 1, 3, 4, 1};
    vector<int> answer = solution(numbers);
    for (int a : answer) cout << a << " ";
    return 0;
}