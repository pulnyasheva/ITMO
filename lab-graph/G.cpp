#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int ver, map<int, set<int>> &graf_color, map<int, set<int>> graf, vector<int> &color) {
    queue<int> q;
    q.push(ver);
    color[ver] = *graf_color[ver].begin();
    for (int element : graf[ver]){
        graf_color[element].erase(color[ver]);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int element : graf[v]){
            if (color[element] == 0){
                color[element] = *graf_color[element].begin();
                for (int el : graf[element]){
                    graf_color[el].erase(color[element]);
                }
                q.push(element);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    vector<int> vertex(n, 0);
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
        vertex[i] = i;
    }
    map<int, set<int>> graf_color;
    map<int, set<int>> graf;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a - 1].insert(b - 1);
        graf[b - 1].insert(a - 1);
        deg[a - 1] += 1;
        deg[b - 1] += 1;
    }
    int k = -1;
    int ver;
    for (int i = 0; i < n; i++) {
        if (deg[i] > k) {
            k = deg[i];
            ver = i;
        }
    }
    int p = k + (1 - (k % 2));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= p; j++) {
            graf_color[i].insert(j);
        }
    }
    bfs(ver, graf_color, graf, color);
    cout << p << "\n";
    for (int i : color){
        cout << i << "\n";
    }
}