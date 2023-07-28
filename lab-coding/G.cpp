#include <iostream>
#include <vector>
#include <valarray>

using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> bk{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<long long> otr(n+1,0);
    vector<long long> ch(n,0);
    for (int i=0; i<n; i++){
        for (int j=0; j< s.size(); j++){
            if (bk[i] == s[j]){
                ch[i]++;
            }
        }
    }
    otr[0]=0;
    otr[n]=pow(s.size(),s.size());
    long long ed = otr[n]/s.size();
    for (int i=1; i<n; i++){
        otr[i] = otr[i-1] + ch[i-1] * ed;
    }
    int index;
    for (int i=0; i<s.size()-1; i++){
        for (int j=0; j < n; j++){
            if (bk[j] == s[i]){
                otr[0] = otr[j];
                otr[n] = otr[j+1];
            }
        }
        ed = (otr[n]-otr[0])/s.size();
        for (int j=1; j<n; j++){
            otr[j] = otr[j-1] + ch[j-1] * ed;
        }
    }
    long long begin, end;
    for (int j=0; j < n; j++){
        if (bk[j] == s[s.size()-1]){
            begin = otr[j];
            end = otr[j+1];
        }
    }
    long q=0;
    long i=1;
    int p;
    while(q==0){
        p=0;
        while(p<pow(2,i)) {
            if (end > (p * pow(s.size(), s.size())) / pow(2, i) && (p * pow(s.size(), s.size())) / pow(2, i) >= begin) {
                q = i;
                break;
            }
            p++;
        }
        i++;
    }
    vector<int> answer;
    while(p > 0)
    {
        answer.push_back(p%2);
        p=p/2;
    }
    if(answer.size() < q){
        for (int j=0; j< q-answer.size();j++){
            answer.push_back(0);
        }
    }
    cout << n << "\n";
    for (int j=0; j< ch.size();j++){
        cout << ch[j] << " ";
    }
    cout << "\n";
    for(int j=answer.size()-1; j >=0; j--){
        cout << answer[j];
    }
}


