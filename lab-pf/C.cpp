#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> a(k);
    vector<int> c(k + 1);
    c[0] = 1;
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    for (int i = 1; i < c.size(); i++){
        cin >> c[i];
        c[i] *= -1;
    }
    vector<long long> multiply(k + 1);
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < c.size(); j++){
            if (i + j < k) {
                multiply[i + j] += a[i] * c[j];
            }
        }
    }
    int degP = multiply.size() - 1;
    for (int i = multiply.size() - 1; i >=0; i--){
        if (multiply[i] == 0){
            degP -= 1;
        } else {
            break;
        }
    }
    cout << degP << "\n";
    for (int i = 0; i < degP + 1; i++){
        cout << multiply[i] << " ";
    }
    cout << "\n";
    cout << c.size() - 1 << "\n";
    for (int elem : c){
        cout << elem << " ";
    }
}
