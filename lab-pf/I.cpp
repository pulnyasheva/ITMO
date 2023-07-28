#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cnst =  104857601;
    int k;
    long long n;
    cin >> k >> n;
    n -= 1;
    vector<long long> a(2 * k);
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    vector<long long> q(k + 1);
    q[0] = 1;
    for(int i = 1; i < k + 1; i++){
        cin >> q[i];
        q[i] = (-q[i] + cnst) % cnst;
    }
    while (n >= k){
        vector<long long> prA;
        vector<long long> prQ(k + 1);
        for (int i = k; i < 2 * k; i++){
            for(int j = 1; j < k + 1; j++) {
                a[i] = (a[i] - q[j] * a[i - j]) % cnst;
                if (a[i] < 0){
                    a[i] += cnst;
                }
            }
        }
        for (int i = 0; i < a.size(); i++){
            if (i % 2 == n % 2){
                prA.push_back(a[i]);
            }
        }
        for (int i = 0; i < k; i++){
            prA.push_back(0);
        }
        a = prA;
        for (int i = 0; i <= k; i++){
            for (int j = 0; j <= k; j++){
                if ((i + j) % 2 == 0) {
                    prQ[(i + j) / 2] = (prQ[(i + j) / 2] + (i % 2 == 1 ? (-q[i] + cnst) % cnst : q[i]) * q[j]) % cnst;
                }
            }
        }
        q = prQ;
        n = n / 2;
    }
    cout << a[n];
}
