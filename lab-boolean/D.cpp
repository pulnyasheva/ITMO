#include <iostream>
#include <vector>

using namespace std;

int pow(int n, int k) {
    int p = 1;
    for (int i = 0; i < k; i++) {
        p = p * n;
    }
    return p;
}

int isNorneN(char c, int index, int n) {
    if (c == '1') {
        return index + 1;
    } else {
        return n + index + 1;
    }
}

void fillTable(vector<vector<int>>& scheme, int n) {
    for (int i = 0; i < n; i++) {
        scheme.push_back({1, i + 1});
    }
    scheme.push_back({2, 1, n + 1});
}

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> strings(pow(2, n));
    vector<int> f(pow(2, n), 0);
    vector<vector<int>> scheme(n + 1);
    for (int i = 0; i < pow(2, n); i++) {
        cin >> strings[i] >> f[i];
    }
    fillTable(scheme, n);
    if (n == 1) {
        if (f[0] == 0 && f[1] == 1) {
            scheme.push_back({3, 1, 3});
        } else if (f[0] == 1 && f[1] == 0) {
            scheme.push_back({3, 2, 3});
        } else if (f[0] == 1 && f[1] == 1) {
            scheme.push_back({3, 1, 2});
        }
    } else {
        int cnt = 0;
        for (int i = 0; i < pow(2, n); i++) {
            if (f[i] == 1) {
                cnt++;
                char c1 = strings[i][0];
                char c2 = strings[i][1];
                scheme.push_back({2, isNorneN(c1, 0, n), isNorneN(c2, 1, n)});
                for (int j = 2; j < n; j++) {
                    char c3 = strings[i][j];
                    scheme.push_back({2, (int) scheme.size() - 1, isNorneN(c3, j, n)});
                }
            }
        }
        int len = scheme.size();
        if (cnt > 1) {
            scheme.push_back({3, 3 * n, 4 * n - 1});
            for (int i = 5 * n - 2; i < len; i += n - 1) {
                scheme.push_back({3, (int) scheme.size() - 1, i});
            }
        }
    }
    cout << scheme.size() - 1 << '\n';
    for (int i = n + 1; i < scheme.size(); i++) {
        for (int j = 0; j < scheme[i].size(); j++) {
            cout << scheme[i][j] << ' ';
        }
        cout << '\n';
    }
}
