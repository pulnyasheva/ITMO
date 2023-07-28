#include <iostream>
#include <vector>

using namespace std;
void gen (int len){
    vector<string> arr(1,"");
    for (int i = 0; i < len; i++){
        int size = arr.size();
        for (int j = 0; j < size; j++){
            string str = arr[arr.size()-j-1-j];
            arr[arr.size()-j-1-j] = "0" + str;
            arr.push_back("1" + str);
        }
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


