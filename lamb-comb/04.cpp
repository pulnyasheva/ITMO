#include <iostream>
#include <vector>
#include <set>

using namespace std;
int pow(int n, int k){
    int p = 1;
    for (int i = 0; i < k; i++){
        p = p*n;
    }
    return p;
}
void gen (int len){
    string s = "";
    set<string> st;
    int count = 0;
    for (int i = 0; i < len; i++){
        s = s + "0";
    }
    while (count < pow(2,len)){
        s.erase(s.begin());
        int size = st.size();
        s.append("1");
        st.insert(s);
        if (st.size() > size){
            count++;
            cout << s << "\n";
        } else {
            count++;
            s.pop_back();
            s.append("0");
            st.insert(s);
            cout << s << "\n";
        }
    }

}
int main() {
    int n;
    cin >> n;
    gen (n);
}


