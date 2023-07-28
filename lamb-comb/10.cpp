#include<iostream>
#include <vector>

using namespace std;

void gen(int n, int k, vector<int> &aps){
    int size_aps = aps.size();
    for (int i = k; i < (n/2+1); i++){
        vector<int> arr;
        for (int j = 0; j < aps.size(); j++){
            arr.push_back(aps[j]);
        }
        int p = n;
        while ((p - i) >= i || p - i == 0 && p > 0){
            p-=i;
            arr.push_back(i);
        }
        if (p != 0){
            arr.push_back(p);
        }
        for (int j = 0; j < arr.size()-1; j++){
            cout << arr[j] << "+";
        }
        cout << arr[arr.size()-1] << "\n";
        int size = arr.size()-2-size_aps;
        for (int j = 0; j < size; j++){
            int m = arr[arr.size()-1] + arr[arr.size()-2];
            arr.pop_back();
            arr.pop_back();
            gen(m, arr[arr.size()-1]+1, arr);
            arr.push_back(m);
        }
    }
    for (int j = 0; j < aps.size(); j++){
        cout << aps[j] << "+";
    }
    cout << n << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(0);
    gen(n,1, arr);
}
