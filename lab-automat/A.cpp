#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    string word;
    int n, m, k;
    set<int> term;
    map<int, vector<pair<int, char>>> condition;
    ifstream in("problem1.in");
    if (in.is_open()) {
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
    }
    in.close();
    std::ofstream out;
    out.open("problem1.out");

    int v = 1;
    bool ok;
    for (int i = 0; i < word.size(); i++){
        ok = false;
        int j = 0;
        while(!ok && j < condition[v].size()){
            if (condition[v][j].second == word[i]){
                v = condition[v][j].first;
                ok = true;
            }
            j++;
        }
        if (!ok){
            out << "Rejects";
            return 0;
        }
    }
    if (term.find(v) != term.end()){
        out << "Accepts";
    } else {
        out << "Rejects";
    }
}
