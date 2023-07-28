#include <iostream>

using namespace std;
void gen (int len, string pref){
    if (pref.size() == len){
        cout << pref << "\n";
        return;
    }
    gen (len, pref + "0");
    gen (len, pref + "1");
}
int main() {
    int n;
    cin >> n;
    gen (n, "");
}


