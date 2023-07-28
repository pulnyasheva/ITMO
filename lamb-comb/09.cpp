#include<iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << (n * 2)); ++i) {
        vector<bool> ans(2 * n);
        int x = i, pos = 2 * n - 1;
        while (x > 0) {
            ans[pos--] = x % 2;
            x /= 2;
        }
        int cntl = 0, cntr = 0;
        bool check = true;
        for (int j = 0; j < 2 * n; ++j) {
            if (!ans[j])
                ++cntl;
            else
                ++cntr;
            if (cntr > cntl) {
                check = false;
                break;
            }
        }
        if (cntl != cntr)
            check = false;
        if (check) {
            for (int j = 0; j < 2 * n; ++j) {
                if (ans[j]) {
                    cout << ')';
                } else {
                    cout << '(';
                }
            }
            cout << endl;
        }
    }
    return 0;
}