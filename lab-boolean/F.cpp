#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int is1Arg(vector<int>& arr){
    int pokazatel = 0;
    int index;
    for (int i=0; i<arr.size();i++) {
        if (arr[i] != -1) {
            index = i;
            pokazatel++;
        }
    }
    if (pokazatel == 1) {
        return index;
    }
    return -1;
}

bool is0(vector<vector<int>>& arr){
    for (int q = 0; q < 105; q++) {
        int pokazatel = 0;
        int index = 0;
        int value;
        for (int i = 0; i< arr.size();i++) {
            if (is1Arg(arr[i]) != -1) {
                pokazatel++;
                index = is1Arg(arr[i]);
                value = arr[i][index];
                arr[i][index] = -1;
                break;
            }
        }
        if (pokazatel == 0){
            return false;
        } else {
            for (int i = 0; i< arr.size();i++) {
                if(arr[i][index]==value){
                    for (int j = 0; j< arr[i].size();j++) {
                        arr[i][j]=-1;
                    }
                } else if(arr[i][index] != -1) {
                    int pokazatel1 = 0;
                    for (int j = 0; j< arr[i].size();j++) {
                        if(arr[i][j] != -1){
                            pokazatel1++;
                        }
                    }
                    if (pokazatel1 == 1){
                        return true;
                    } else {
                        arr[i][index] = -1;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> arr(k, vector<int> (n, 0));
    for (int i = 0; i<k; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    if (is0(arr)){
        cout << "YES";
    } else {
        cout << "NO";
    }
}
