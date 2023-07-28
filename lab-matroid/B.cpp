#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
vector<vector<pair<long long, int>>> graf;

void treeMax(vector<int> &p, vector<int> &key, vector<pair<int, int>> &e, int & n) {
    set<pair<int, int>> q;
    int v = 0;
    key[v] = e.size();
    for (int i = 0; i < key.size(); i++) {
        q.insert(make_pair(key[i], i));
    }
    while (!q.empty()) {
        auto it = *(--q.end());
        int vertex = it.second;
        q.erase(it);
        for (int i = 0; i < n; i++) {
            if (i != vertex) {
                pair<long long, int> element;
                int first, second;
                if (i > vertex) {
                    element = graf[i][vertex];
                    first = i;
                    second = vertex;
                } else {
                    element = graf[vertex][i];
                    first = vertex;
                    second = i;
                }
                int dis = distance(e.begin(), std::find(e.begin(), e.end(), make_pair(first, second)));
                if (element.second > 0) {
                    if (q.find(make_pair(key[i], i)) != q.end() and key[i] < dis) {
                        q.erase(make_pair(key[i], i));
                        p[i] = vertex;
                        key[i] = dis;
                        q.insert(make_pair(key[i], i));
                    }
                }
            }
        }
    }
}

bool comp(pair<int, int> &first, pair<int, int> &second) {
    return graf[first.first][first.second].first < graf[second.first][second.second].first;
}

int main() {
    freopen("destroy.in", "r", stdin);
    freopen("destroy.out", "w", stdout);
    int n, m;
    long long s;
    cin >> n >> m >> s;
    vector<int> p(n, -1);
    vector<pair<int, int>> e;
    vector<int> key(n, -1);
    graf.resize(n);
    for (int i = 0; i < n; i++) {
        graf[i].resize(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long weightE;
        cin >> a >> b >> weightE;
        if (a > b) {
            e.emplace_back(make_pair(a - 1, b - 1));
        } else {
            e.emplace_back(make_pair(b - 1, a - 1));
        }
        if (a > b) {
            graf[a - 1][b - 1] = make_pair(weightE, i + 1);
        } else {
            graf[b - 1][a - 1] = make_pair(weightE, i + 1);
        }
    }
    sort(e.begin(), e.end(), comp);
    treeMax(p, key, e, n);
    int ans = 0;
    long long sum = 0;
    vector<int> number;
    for (int i = 0; sum <= s and i < e.size(); i++) {
        auto element = e[i];
        if (sum + graf[element.first][element.second].first > s) {
            break;
        }
        if (!(p[element.first] == element.second or p[element.second] == element.first)) {
            ans += 1;
            sum += graf[element.first][element.second].first;
            number.emplace_back(graf[element.first][element.second].second);
        }
    }
    cout << ans << "\n";
    sort(number.begin(), number.end());
    for (auto element: number) {
        cout << element << " ";
    }
    return 0;
}