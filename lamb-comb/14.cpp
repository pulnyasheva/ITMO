#include <iostream>
#include <vector>

using namespace std;
bool isNumberInPref(int ch, vector<int> str, int size){
    bool b = false;
    for (int i = 0; i < size; i++){
        if (str[i] == ch){
            b = true;
            return b;
        }
    }
    return b;
}
long long fact(int n){
    long long p = 1;
    for(int i = 1; i < n+1; i++){
        p = p*i;
    }
    return p;
}
void gen(int n, vector<int> ar) {
    long long p = 0;
    vector<int> arr(0);
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 1; j < ar[i]; j++){
            if (!isNumberInPref(j, ar, i+1)){
                count++;
            }
        }
        if (count != 0) {
            p += count * fact(n-i-1);
        }
    }
    cout << p;
    return;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    gen(n,arr);
}

