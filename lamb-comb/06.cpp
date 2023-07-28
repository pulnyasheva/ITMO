#include <iostream>
#include <vector>

using namespace std;
vector<string> arr(0);
void gen (int len, string pref){

    if (pref.size() == len){
        arr.push_back(pref);
        return;
    }
    gen (len, pref + "0");
    if (pref[pref.size()-1] != '1') {
        gen(len, pref + "1");
    }
}
int main() {
    int n;
    cin >> n;
    gen(n,"");
    cout << arr.size() << "\n";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\n";
    }
}