#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, d;
    cin >> r >> d;
    vector<long long> p(d + 1);
    for (int i = 0; i < d + 1; i++) {
        cin >> p[i];
    }
    if (d == 0){
        cout << "0" << "\n";
        cout << p[0] << "\n";
        cout << "1" << "\n";
        cout << "1 " << -r;
        return 0;
    }
    vector<vector<long long>> c(d);
    vector<long long> fact(d);
    c[0] = {1, 1};
    fact[0] = 1;
    for (int i = 1; i < d; i++) {
        fact[i] = fact[i - 1] * (i + 1);
        c[i].resize(i + 2);
        vector<long long> mn = {i + 1, 1};
        for (int j = 0; j < mn.size(); j++) {
            for (int k = 0; k < c[i - 1].size(); k++) {
                c[i][j + k] += mn[j] * c[i - 1][k];
            }
        }
    }
    vector<long long> kf(d + 1, 0);
    for (int i = d; i >= 1; i--) {
        kf[i] = (p[i] - kf[i]) * fact[i - 1];
        for (int j = 0; j < i; j++) {
            kf[j] += (kf[i] / fact[i - 1]) * c[i - 1][j];
        }
    }
    kf[0] = p[0] - kf[0];
    vector<vector<long long>> zn(d + 1);
    zn[0] = {1, -r};
    for (int i = 1; i < d + 1; i++){
        zn[i].resize(i + 2);
        for(int j = 0; j < zn[0].size(); j++){
            for (int k = 0; k < zn[i - 1].size(); k++){
                zn[i][j + k] += zn[0][j] * zn[i - 1][k];
            }
        }
    }
    vector<long long> ch(d + 1);
    for (int i = 0; i < kf.size() - 1; i++){
        for (int j = 0; j < zn[d - 1 - i].size(); j++){
            ch[j] += zn[d - 1 - i][j] * kf[i];
        }
    }
    ch[0] += kf[d];
    int deg = ch.size() - 1;
    for (int i = ch.size() - 1; i >= 0; i--){
        if (ch[i] == 0){
            deg -= 1;
        } else {
            break;
        }
    }
    cout << ch.size()  - 1 << "\n";
    for (long long elem : ch){
        cout << elem << " ";
    }
    cout << "\n";
    cout << zn[d].size()  - 1 << "\n";
    for (long long elem : zn[d]){
        cout << elem << " ";
    }
}
