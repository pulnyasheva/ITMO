#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int k;
    cin >> k;
    int n=1;
    for (int i=0; i< k; i++){
        n = n*2;
    }
    string arr1[n];
    vector<int> arr2(n);
    for (int i=0; i<n; i++){
        cin >> arr1[i];
        cin >> arr2[i];
    }
    cout << arr1[0] << ' ' << arr2[0] << '\n';
    int kf;
    for(int i=n; i>1; i--){
        for (int j=0; j<i-1;j++){
            kf = (arr2[j]+arr2[j+1])%2;
            arr2[j] = kf;
        }
        cout << arr1[n+1-i] << ' ' << arr2[0] << '\n';
    }
}

