#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    cin >> n;
    string s = "((A0|B0)|(A0|B0))";
    for (int i =1; i< n; i++){
       string j = to_string(i);
       s = "((" + s + "|((A" + j + "|A"+ j + ")|(B" + j + "|B" + j + ")))|(A" + j + "|B" + j +"))";
    }
    cout << s;
}
