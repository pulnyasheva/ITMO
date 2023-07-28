#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    long long cnst = 1e9 + 7;
    std::ofstream out;
    ifstream in("problem4.in");
    out.open("problem4.out");
    int n, m, k, l;
    set<int> term;
    map<int, vector<int>> condition;
    in >> n >> m >> k >> l;
    for (int i = 0; i < k; i++) {
        int terminal;
        in >> terminal;
        term.insert(terminal);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        in >> a >> b >> c;
        condition[a].push_back(b);
    }
    in.close();
    vector<long long> count(n);
    count[0] = 1;
    vector<long long> changeable;
    for (int i = 0; i < l; i++){
        changeable.clear();
        changeable.resize(n);
        for (auto it = condition.begin(); it != condition.end(); ++it) {
            for (int j = 0; j < (it->second).size(); j++) {
                changeable[(it->second)[j] - 1] += count[it->first - 1] % cnst;
            }
        }
        count = changeable;
    }
    long long answer = 0;
    for (std::set<int>::iterator it = term.begin(); it != term.end(); ++it) {
       answer += count[*it - 1] % cnst;
    }
    out << answer % cnst;
    return 0;
}

