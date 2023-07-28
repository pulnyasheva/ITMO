#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int association(int m, int v, int u, map<int, set<int>> &graf){
    int begin_e = graf[u].size() + graf[v].size();
    if (!graf[u].empty()){
        for(int vertex : graf[u]){
            graf[v].insert(vertex);
            graf[vertex].erase(u);
            graf[vertex].insert(v);
        }
    }
    int end_e = graf[v].size();
    return m - (begin_e - end_e);
}

void xromatmn(int n, int m, map<int, set<int>> graf, vector<int> &mn, int minus){
    if (m == 0){
        if (minus % 2 == 1){
            mn[n] -= 1;
        } else {
            mn[n] += 1;
        }
        return;
    }
    int v = graf.begin()->first;
    int u = *graf.begin()->second.begin();
    graf[v].erase(u);
    if (graf[v].empty()){
        graf.erase(v);
    }
    graf[u].erase(v);
    if (graf[u].empty()){
        graf.erase(u);
    }
    xromatmn(n, m - 1, graf, mn, minus);
    int s_u = 0;
    int s_v = 0;
    if (graf.find(u) != graf.end()){
        s_u = graf[u].size();
    }
    if (graf.find(v) != graf.end()){
        s_v = graf[v].size();
    }
    int begin_e = s_u + s_v;
    if (s_u != 0){
        for(int vertex : graf[u]){
            graf[v].insert(vertex);
            graf[vertex].erase(u);
            graf[vertex].insert(v);
        }
        graf.erase(u);
    }
    int end_e = 0;
    if (graf.find(v) != graf.end()){
        end_e = graf[v].size();
    }
    int assoc_m = m - 1 - (begin_e - end_e);
    xromatmn(n - 1, assoc_m, graf, mn, minus + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, set<int>> graf;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a - 1].insert(b - 1);
        graf[b - 1].insert(a - 1);
    }
    vector<int> mn(n + 1, 0);
    cout << n << "\n";
    xromatmn(n, m, graf, mn, 0);
    for(int i = n; i >=0; i--){
        cout << mn[i] << " ";
    }
}