#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> cod(N - 2, 0);
    set<int> vertex;
    set<int> min_vertex;
    vector<int> count(N, 0);
    for (int i = 0; i < N; i++){
        vertex.insert(i);
    }
    for (int i = 0; i < N - 2; i++){
        cin >> cod[i];
        cod[i] -= 1;
        count[cod[i]] += 1;
    }
    for (int i = 0; i < N; i++){
        if (count[i] == 0){
            min_vertex.insert(i);
        }
    }
    for (int i = 0; i < N - 2; i++){
        int x = *min_vertex.cbegin();
        min_vertex.erase(x);
        cout << x + 1 << " " << cod[i] + 1 << "\n";
        count[cod[i]] -= 1;
        if (count[cod[i]] == 0 && vertex.count(cod[i]) == 1){
            min_vertex.insert(cod[i]);
        }
        vertex.erase(x);
    }
    auto it = vertex.cbegin();
    cout << *it + 1 << " " << *(++it) + 1;
}
