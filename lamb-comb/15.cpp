#include <iostream>
#include <vector>

using namespace std;
int n, k;
long long m;
void c(vector<vector<long long>> &arr){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (j == 0){
                arr[i][j] = 1;
            } else if (i < j){
                arr[i][j] = 0;
            } else {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }
    return;
}
void gen(int n, int k, long long m, vector<vector<long long>> &arr) {
    c(arr);
    int count = 0;
    int k_1 = k;
    int a = 1;
    while (true) {
        if (m <= arr[n-1][k-1]) {
            cout << a << " ";
            count++;
            if (count == k_1){
                return;
            }
            k -= 1;
        } else {
            m -= arr[n-1][k-1];
        }
        n -= 1;
        a += 1;
    }
}

int main() {
    cin >> n >> k >>m;
    vector<vector<long long>> arr(n, vector<long long>(k, 0));
    gen(n,k,m+1, arr);
    return 0;
}

