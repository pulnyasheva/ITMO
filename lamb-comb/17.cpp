#include <iostream>
#include <vector>

using namespace std;
int n;
long long k;
void dp(vector<vector<long long>> &arr){
    for (int i = 0; i < 2 * n; i++){
        for (int j = 0; j < n + 1; j++){
            if (i==j && j==0){
                arr[i][j] = 1;
            } else if (i == 0){
                arr[i][j] = 0;
            } else if (j == 0){
                arr[i][j] = arr[i-1][j+1];
            } else if (j == n){
                arr[i][j] == arr[i-1][j-1];
            } else {
                arr[i][j] = arr[i-1][j+1] + arr[i-1][j-1];
            }
        }
    }
    return;
}
void gen(int n, long long k, vector<vector<long long>> &arr) {
    dp(arr);
    long long b = 1;
    if (k ==0){
        for (int i = 0; i < n; i++){
            cout << "(";
        }
        for (int i = 0; i < n; i++){
            cout << ")";
        }
        return;
    }
    for (int i = 0; i < n * 2; i++){
        long long p;
        if (b < 0){
            p = 0;
        } else {
            p = arr[n*2 - 1 - i][b];
        }
        if (k <= arr[n*2 - 1 - i][b]) {
            cout << "(";
            b++;
        } else {
            k -= p;
            cout << ")";
            b--;
        }
    }
}

int main() {
    cin >> n >> k;
    vector<vector<long long>> arr(2*n, vector<long long>(n + 1, 0));
    gen(n,k, arr);
    return 0;
}

