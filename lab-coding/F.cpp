#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> kod(n,0);
    for (int i=0; i<n; i++){
        cin >> kod[i];
    }
    string word;
    vector<string> sl{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int nomer = kod[0];
    word += sl[nomer];
    string t = sl[nomer];
    for (int i=1; i< kod.size(); i++){
        if (kod[i]<sl.size()){
            t += sl[kod[i]][0];
            sl.insert(sl.end(),t);
            t = sl[kod[i]];
            word += sl[kod[i]];
        } else {
            t += t[0];
            sl.insert(sl.end(),t);
            t = sl[kod[i]];
            word += sl[kod[i]];
        }
    }
//    word += sl[kod[kod.size()-1]];
    cout << word;
}