#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    std::ofstream out;
    ifstream in("problem2.in");
    out.open("problem2.out");
    string word;
    int n, m, k;
    set<int> term;
    map<int, vector<pair<int, char>>> condition;
    in >> word >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int terminal;
        in >> terminal;
        term.insert(terminal);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        in >> a >> b >> c;
        condition[a].push_back(make_pair(b, c));
    }
    in.close();
    bool ok;
    set<int> v = {1};
    set<int> changeable;
    for (int i = 0; i < word.size(); i++) {
        changeable.clear();
        ok = false;
        for (std::set<int>::iterator it = v.begin(); it != v.end(); ++it) {
            for (int j = 0; j < condition[*it].size(); j++) {
                if (condition[*it][j].second == word[i]) {
                    changeable.insert(condition[*it][j].first);
                    ok = true;
                }
            }
        }
        v = changeable;
        if (!ok) {
            out << "Rejects";
            return 0;
        }
    }
    for (std::set<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (term.find(*it) != term.end()){
            out << "Accepts";
            return 0;
        }
    }
    out << "Rejects";
    return 0;
}

