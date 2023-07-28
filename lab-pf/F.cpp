#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnst = 1e9 + 7;
    int k, m;
    cin >> k >> m;
    vector<int> weight(k);
    vector<long long> answer(m + 1);
    vector<long long> tree(m + 1, -1);
    tree[0] = 1;
    answer[0] = 1;
    for (int i = 0; i < k; i++){
        cin >> weight[i];
    }
    std::sort(weight.begin(), weight.end());
    for (int i = 1; i <= m; i++){
        for (int j = 0; j <= i; j++){

        }
    }

    for (int i = 1; i <= m; i++){
        for (int j = 0; j < k; j++){
            if (weight[j] <= i){
                if (tree[i - weight[j]] == -1) {
                    tree[i - weight[j]] = 0;
                    for (int c = 0; c <= (i - weight[j]) / 2; c++) {
                        long long d;
                        if (c != (i - weight[j] - c)) {
                            d = (2 * answer[c] * answer[i - weight[j] - c]) % cnst;
                        } else {
                            d = (answer[c] * answer[i - weight[j] - c]) % cnst;
                        }
                        answer[i] = (answer[i] + d) % cnst;
                        tree[i - weight[j]] = (tree[i - weight[j]] + d) % cnst;
                    }
                } else {
                    answer[i] = (answer[i] + tree[i - weight[j]]) % cnst;
                }
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        cout << answer[i] << " ";
    }
}
