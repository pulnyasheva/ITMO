#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<int> w, d;

bool comp (int first, int second) {
    if (w[first] == w[second]){
        return d[first] > d[second];
    }
    return w[first] > w[second];
}

int main() {
    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> index;
    for (int i = 0; i < n; i++){
        int d0, v0;
        cin >> d0 >> v0;
        d.emplace_back(d0);
        w.emplace_back(v0);
        index.emplace_back(i);
    }
    set<int> used_time;
    auto maxD = max_element(d.begin(), d.end());
    for (int i = 1; i <= *maxD; i++){
        used_time.insert(i);
    }
    sort(index.begin(), index.end(), comp);
    for (int i = 0; i < n; i++){
        if (!used_time.empty()){
            auto it = used_time.upper_bound(d[index[i]]);
            if (it != used_time.begin()){
                --it;
                used_time.erase(*it);
                w[index[i]] = 0;
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++){
        answer += w[i];
    }
    cout << answer;
    return 0;
}