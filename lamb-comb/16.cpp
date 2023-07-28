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
void gen(int n, int k, vector<int> &ar, vector<vector<long long>> &arr) {
    c(arr);
    long long m = 0;
    int count = 0;
    int k_1 = k;
    int a = 1;
    while (true) {
        if (a == ar[count]) {
            count++;
            if (count == k_1){
                cout << m;
                return;
            }
            k -= 1;
        } else {
            m+=arr[n-1][k-1];
        }
        n -= 1;
        a += 1;
    }
}

int main() {
    cin >> n >> k;
    vector<vector<long long>> arr(n, vector<long long>(k, 0));
    vector<int> ar(k);
    for (int i = 0; i < k; i++){
        cin >> ar[i];
    }
    gen(n,k,ar, arr);
    return 0;
}

