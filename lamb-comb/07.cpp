#include <iostream>

using namespace std;
bool isNumberInPref(char ch, string str){
    bool b = false;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == ch){
            b = true;
        }
    }
    return b;
}
void gen (int n, string pref){
    if (pref.size() == n){
        for (int i = 0; i < pref.size(); i++){
            cout << pref[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i < n+1;i++){
        if (!isNumberInPref((char) (i + '0'), pref)){
            gen (n, pref + (char) (i + '0'));
        }
    }
}
int main() {
    int n;
    cin >> n;
    gen(n,"");
}