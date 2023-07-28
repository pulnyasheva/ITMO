#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> graf(N, vector<int>(N, 0));
    for (int i = 1; i < N; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < i; j++){
            graf[i][j] = st[j] - '0';
            graf[j][i] = graf[i][j];
        }
    }
    deque<int> deque;
    for (int i = 0; i < N; i++){
        deque.emplace_back(i);
    }
    for (int i = 0; i < N * (N - 1); i++){
        int first, second;
        first = deque[0];
        second = deque[1];

        if (graf[first][second] == 1) {
            deque.pop_front();
            deque.emplace_back(first);
        } else {
            int j = 2;
            while (graf[first][deque[j]] == 0 or graf[second][deque[j + 1]] == 0){
                j++;
            }
            for (int k = 0; 1 + k < j - k; k++){
                int cur1 = deque[1 + k];
                int cur2 = deque[j - k];
                deque.emplace(deque.erase(deque.cbegin() + 1 + k), cur2);
                deque.emplace(deque.erase(deque.cbegin() + j - k), cur1);
            }
        }
    }
    for (auto it = deque.cbegin(); it != deque.cend(); ++it){
        cout << *it + 1 << " ";
    }
}
