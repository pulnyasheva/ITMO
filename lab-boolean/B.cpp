#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int pow(int n, int k){
    int p=1;
    for (int i=0; i<k;i++) {
        p = p * n;
    }
    return p;
}
string stringArg(int n,int ns){
    string arr;
    for (int i=n-1; i>-1; i--){
        if (ns>= pow(2,i)){
            arr = arr + '1';
            ns -= pow(2,i);
        } else{
            arr = arr + '0';
        }
    }
    return arr;
}

bool is0(vector<int> arr){
   return arr[0]==0;
}

bool is1(vector<int> arr){
    return arr.back()==1;
}
bool isSam(vector<int> arr){
    if (arr.size()==1){
        return arr[0];
    }
    for (int i=0; i< arr.size()/2; i++){
        if (arr[i] == arr[arr.size()-1-i]){
            return false;
        }
    }
    return true;
}
bool isLine(vector<int> arr, int st){
    int kf;
    string ans;
    for (int i=arr.size(); i>1; i--){
        for(int j=0; j<i-1; j++){
            kf = (arr[j]+arr[j+1])%2;
            arr[j] = kf;
        }
        ans = stringArg(st, arr.size()+1-i);
        if (count(ans.begin(), ans.end(), '1') > 1 && arr[0]==1){
            return false;
        }
    }
    return true;
}
bool isMonot(vector<int> arr, int st){
    for (int j=0; j< pow(2, st); j++){
        for(int i=0; i< j; i++){

            string ans1 = stringArg(st, i);
            string ans2 = stringArg(st, j);
            int f = 0;
            for (int k=0; k<st; k++){
                if (ans1[k]>ans2[k]){
                    f = 1;
                }
            }
            if (f==0 && arr[i]>arr[j]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int st;
    int len;
    char argument;
    string thisf;
    int pr=0;
    bool f0, f1, f2, f3, f4;
    f0 = f1 = f2 = f3 = f4 = true;
    for (int i=0; i<n; i++){
        cin >> st;
            len = 1;
            for (int j = 0; j < st; j++) {
                len = len * 2;
            }
            vector<int> arr(len, 0);
            cin >> thisf;
            for (int j = 0; j < len; j++) {
                argument = thisf[j];
                arr[j] = argument - '0';
            }
            if (f0) {
                f0 = is0(arr);
            }
            if (f1) {
                f1 = is1(arr);
            }
            if (f2) {
                f2 = isSam(arr);
            }
            if (f3) {
                f3 = isMonot(arr, st);
            }
            if (f4) {
                f4 = isLine(arr, st);
            }
    }
    if (f0 || f1 || f2 || f3 || f4){
        cout << "NO";
    } else{
        cout << "YES";
    }
}

