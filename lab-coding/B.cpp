#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> str(s.size(), " ");
    str[0] = s;
    for (int i=1; i< s.size();i++){
        char ch = s[s.size()-1];
        s = ch + s;
        s.pop_back();
        str[i] = s;
    }
    sort(str.begin(), str.end());
    string answer;
    for (int i=0; i < str.size(); i++ ){
        s = str[i];
        answer += s[s.size()-1];
    }
    cout << answer;
}