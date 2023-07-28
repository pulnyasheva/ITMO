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
    vector<int> count(N, 0);
    set<int> vertex;
    map<int, set<int>> graf;
    for (int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        count[u - 1] += 1;
        count[v - 1] += 1;
        graf[u - 1].insert(v - 1);
        graf[v - 1].insert(u - 1);
    }
    for (int i = 0; i < N - 1; i++){
        if (count[i] == 1){
            vertex.insert(i);
        }
    }
    for (int i = 0; i < N - 2; i++){
        auto it = vertex.cbegin();
        int v = *graf[*it].cbegin();
        cout << v + 1 << " ";
        count[v] -= 1;
        if (count[v] == 1){
            vertex.insert(v);
        }
        graf[v].erase(*it);
        vertex.erase(*it);
    }
}
