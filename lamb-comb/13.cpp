#include <iostream>
#include <vector>

using namespace std;
bool isNumberInPref(int ch, vector<int> &str){
    bool b = false;
    for (int i = 0; i < str.size(); i++){
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
void gen(long long n, long long k) {
    long long p;
    vector<int> arr(0);
    for (int i = 0; i < n; i++) {
        long long f = fact(n-i-1);
        p = k / f;
        k %= f;
        int count = 0;
        for (int j = 1; j < n+1; j++){
            if (!isNumberInPref(j, arr)){
                count++;
                if (count == p+1){
                    arr.push_back(j);
                    cout << j << " ";
                    if (arr.size() == n){
                        return;
                    }
                }
            }
        }
    }
    return;
}
int main() {
    long long n, k;
    cin >> n >> k;
    gen(n,k);
}

