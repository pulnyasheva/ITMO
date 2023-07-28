#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    std::ofstream out;
    ifstream in("automaton.in");
    out.open("automaton.out");
    int n, m;
    string start;
    map<char, vector<string>> conditions;
    vector<string> words;
    in >> n >> start;
    for (int i = 0; i < n; i++) {
        char neterm;
        string condition;
        in >> neterm >> condition >> condition;
        conditions[neterm].push_back(condition);
    }
    in >> m;
    for (int i = 0; i < m; i++) {
        string word;
        in >> word;
        words.push_back(word);
    }
    in.close();
    bool ok;
    set<string> next_neterm = {start};
    set<string> changeable;
    for(int w = 0; w < words.size(); w++){
        next_neterm = {start};
        bool print = false;
        for (int i = 0; i < words[w].size(); i++) {
            changeable.clear();
            ok = false;
            for (auto it = next_neterm.begin(); it != next_neterm.end(); ++it) {
                if ((*it).size() > 1){
                    for (int j = 0; j < conditions[(*it)[1]].size(); j++) {
                        if (conditions[(*it)[1]][j][0] == words[w][i]) {
                            changeable.insert(conditions[(*it)[1]][j]);
                            ok = true;
                        }
                    }
                }
                if (*it == start){
                    for (int j = 0; j < conditions[(*it)[0]].size(); j++) {
                        if (conditions[(*it)[0]][j][0] == words[w][i]) {
                            changeable.insert(conditions[(*it)[0]][j]);
                            ok = true;
                        }
                    }
                }
            }
            next_neterm = changeable;
            if (!ok) {
                out << "no\n";
                print = true;
                break;
            }
        }
        for (auto it = next_neterm.begin(); it != next_neterm.end(); ++it) {
            if ((*it)[0] == words[w][words[w].size() - 1] && (*it).size() == 1){
                out << "yes\n";
                print = true;
                break;
            }
        }
        if (!print){
            out << "no\n";
        }
    }
}

