#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> str(s.size(), "");
    sort(str.begin(), str.end());
    for (int j=0; j< s.size(); j++) {
        for (int i = 0; i < s.size(); i++) {
            str[i] = s[i]+str[i];
        }
        sort(str.begin(), str.end());
    }
    string answer = str[0];
    cout << answer;
}