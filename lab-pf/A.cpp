#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cnst = 998244353;
    int n, m;
    cin >> n >> m;
    vector<long long> p(n + 1);
    vector<long long> q(m + 1);
    for (int i = 0; i < n + 1; i++){
        cin >> p[i];
    }
    for (int i = 0; i < m + 1; i++){
        cin >> q[i];
    }
    cout << max(n, m) << "\n";
    for (int i = 0; i < max(n, m) + 1; i++){
        if (i < min(n, m) + 1){
            cout << (p[i] + q[i]) % cnst << " ";
        } else {
            if (n == max(n, m)){
                cout << p[i] << " ";
            } else {
                cout << q[i] << " ";
            }
        }
    }
    cout << "\n";
    vector<long long> multiply(n + m + 1);
    cout << n + m << "\n";
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++){
            multiply[i + j] = (multiply[i + j] + (p[i] * q[j])) % cnst;
        }
    }
    for (long long elem : multiply){
        cout << elem << " ";
    }
    cout << "\n";
    vector<long long> del(1000, 0);
    vector<long long> c(1000, 0);
    c[0] = 1;
    for (int i = 1; i < 1000; i++){
        for (int j = 1; j <= i; j++){
            if (j < q.size()) {
                c[i] = (c[i] - (q[j] * c[i - j])) % cnst;
            }
        }
    }
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < p.size(); j++){
            if (i + j < 1000) {
                del[i + j] = (del[i + j] + (c[i] * p[j])) % cnst;
            }
        }
    }

    for (long long elem : del){
        if (elem >= 0) {
            cout << elem << " ";
        } else {
            cout << elem + cnst << " ";
        }
    }
}
