#include <iostream>
#include <vector>

using namespace std;
string st;
int n;
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
void gen(string str, vector<vector<long long>> &arr) {
    dp(arr);
    long long answer = 0;
    long long p;
    int b = 1;
    int count=0;
    for (int i = 0; i < n; i++){
        if (str[i] == '('){
            count++;
        }
    }
    if (count == n){
        cout << answer;
        return;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (b < 0) {
            p = 0;
        } else {
            p = arr[n * 2 - 1 - i][b];
        }
        if (str[i] == '(') {
            b++;
        } else {
            answer += p;
            b--;
        }
    }
    cout << answer+1;
    return;
}

int main() {
    cin >> st;
    n = st.size()/2;
    vector<vector<long long>> arr(2*n, vector<long long>(n + 1, 0));
    gen(st, arr);
    return 0;
}

