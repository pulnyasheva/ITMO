#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graf;

bool comp(int a, int b) {
    return graf[a][b] == 1;
}

void mergeSort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n - i; j += 2 * i) {
            vector<int> result(min(j + 2 * i, n) - j);
            merge(a.begin() + j, a.begin() + j + i, a.begin() + j + i, a.begin() + min(j + 2 * i, n), result.begin(),
                  comp);
            for (int k = 0; k < min(j + 2 * i, n) - j; k++) {
                a[j + k] = result[k];
            }
        }
    }
}

std::deque<int>::iterator iter(int ver, deque<int> &deque) {
    for (auto it = deque.begin(); it != deque.end(); it++) {
        if (graf[ver][*it] == 1) {
            return it;
        }
    }
    return deque.end();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    graf.resize(N, vector<int>(N, 0));
    vector<int> vertex(N);
    for (int i = 0; i < N; i++){
        vertex[i] = i;
    }

    for (int i = 1; i < N; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < i; j++){
            graf[i][j] = st[j] - '0';
            graf[j][i] = 1 - graf[i][j];
        }
    }

    mergeSort(vertex);
    int k = 1;
    if (graf[vertex[N- 1]][vertex[0]] == 1){
        for (int v : vertex){
            cout << v + 1 << " ";
        }
    } else {
        for (int i = N - 2; i >= 2; i--){
            if (graf[vertex[i]][vertex[0]] == 1){
                k = i + 1;
                break;
            }
        }
        deque<int> deque;
        for (int i = 0; i < k; i++){
            deque.emplace_back(vertex[i]);
        }
        int count = 0;
        int begin = k;
        while (k < N){
            auto it = iter(vertex[k], deque);
            if (it != deque.end()){
                deque.insert(it, vertex.begin() + begin, vertex.begin() + begin + count + 1);
                begin = k + 1;
                count = 0;
            } else {
                count++;
            }
            k++;
        }
        for (int element : deque){
            cout << element + 1 << " ";
        }
    }

}
