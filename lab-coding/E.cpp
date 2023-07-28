#include <iostream>
#include <vector>

using namespace std;
int main() {
    string s;
    cin >> s;
    vector<string> sl{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    string t = "";
    int flag;
    for (int i = 0; i < s.size();i++){
        string t1 = t + s[i];
        flag = 0;
        for (int j = 0; j< sl.size(); j++){
            if (t1 == sl[j]){
                t = t1;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (int j = 0; j < sl.size(); j++) {
                if (t == sl[j]) {
                    cout << j  << " ";
                    sl.insert(sl.end(),t1);
                    t = s[i];
                    break;
                }
            }
        }
    }
    for (int j = 0; j < sl.size(); j++) {
        if (t == sl[j]) {
            cout << j << " ";
        }
    }
}

