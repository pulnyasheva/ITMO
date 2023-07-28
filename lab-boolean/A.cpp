#include <iostream>
#include <vector>

using namespace std;
bool isReflexive(vector<vector<int>> arr){
    for (int i=0; i< arr.size(); i++){
        if (arr[i][i] != 1){
            return false;
        }
    }
    return true;
}
bool isAnReflexive(vector<vector<int>> arr){
    for (int i=0; i< arr.size(); i++){
        if (arr[i][i] != 0){
            return false;
        }
    }
    return true;
}
bool isSymmetrical(vector<vector<int>> arr){
    for (int i=0; i< arr.size(); i++){
        for (int j=0; j < arr.size(); j++){
            if(arr[i][j] != arr[j][i]){
                return false;
            }
        }
    }
    return true;
}
bool isAnSymmetrical(vector<vector<int>> arr){
    for (int i=0; i< arr.size(); i++){
        for (int j=0; j < arr.size(); j++){
            if((arr[i][j] == arr[j][i]) && arr[i][j] == 1 && i != j){
                return false;
            }
        }
    }
    return true;
}
bool isTranspore(vector<vector<int>> arr){
    for (int i=0; i< arr.size(); i++){
        for (int j=0; j < arr.size(); j++){
            for (int k=0; k< arr.size(); k++){
                if((arr[i][j] && arr[j][k]) == 1 && arr[i][k] != 1){
                    return false;
                }
            }
        }
    }
    return true;
}

void writeInformation(vector<vector<int>>& arr) {
    cout << isReflexive(arr) << ' ';
    cout << isAnReflexive(arr) << ' ';
    cout << isSymmetrical(arr) << ' ';
    cout << isAnSymmetrical(arr) << ' ';
    cout << isTranspore(arr) << '\n';

}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr1(n, vector<int> (n, 0));
    vector<vector<int>> arr2(n, vector<int> (n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr2[i][j];
        }
    }
    writeInformation(arr1);
    writeInformation(arr2);
    int p;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            p=0;
            for (int k=0; k<n; k++){
                if (arr1[i][k]*arr2[k][j] == 1){
                    p=1;
                }
            }
            cout << p << ' ';
        }
        cout << '\n';
    }
}
