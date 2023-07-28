#include <iostream>
#include <vector>

using namespace std;
int main() {
    string s;
    cin >> s;
    vector<char> bk{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < s.size();i++){
        for (int j = 0; j< bk.size(); j++){
            char ch;
            if (s[i]==bk[j]){
                cout << j+1 << " ";
                ch = bk[j];
                bk.erase(bk.begin() + j);
                bk.insert(bk.begin(), ch);
            }
        }
    }
}
