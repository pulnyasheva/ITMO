#include<iostream>
#include <vector>

using namespace std;

void gen (int n, vector<int> &pref){
    if (!pref.empty() && pref[pref.size()-1] == 0){
        for (int i = 0; i < pref.size()-1; i++){
            cout << pref[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n+1;i++){
        if (pref.empty() || i > pref[pref.size()-1] || i == 0){
            pref.push_back(i);
            gen (n, pref);
            pref.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(0);
    gen(n, arr);
}

