#include <iostream>
#include <vector>

using namespace std;
void gen (int n,int k, vector<int> &pref){
    if (pref.size() == k){
        for (int i = 0; i < k; i++){
            cout << pref[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i < n+1;i++){
        if (pref.empty() || i > pref[pref.size()-1]){
            pref.push_back(i);
            gen (n,k, pref);
            pref.pop_back();
        }
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(0);
    gen(n, k, arr);
}
