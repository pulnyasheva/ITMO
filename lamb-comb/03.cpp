#include <iostream>
#include <vector>

using namespace std;
int pow(int n, int k){
    int p=1;
    for (int i=0; i<k;i++) {
        p = p * n;
    }
    return p;
}
void gen (int len){
    vector<string> arr(pow(3, len),"");
    int size = 1;
    for (int i = 0; i < len; i++){
        for (int j = 1; j < size+1; j++){
            if (j%3==1) {
                string str = arr[j - 1];
                arr[j - 1] = "0" + str;
                arr[size + j -1] = "1" + str;
                arr[(size) * 2 + j -1] = "2" + str;
            } else if (j%3==2) {
                string str = arr[j - 1];
                arr[j - 1] = "1" + str;
                arr[size + j -1] = "2" + str;
                arr[size * 2 + j -1] = "0" + str;
            } else {
                string str = arr[j - 1];
                arr[j - 1] = "2" + str;
                arr[size + j - 1] = "0" + str;
                arr[(size) * 2 + j -1] = "1" + str;
            }
        }
        size *=3;
    }
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\n";
    }
}
int main() {
    int n;
    cin >> n;
    gen (n);
}

