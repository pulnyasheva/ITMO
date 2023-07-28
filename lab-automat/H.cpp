#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

namespace {
    void dfs(map<int, map<char, int>> &condition, int v, vector<int> &visited) {
        visited[v] = 1;
        for (auto it = condition[v].begin(); it != condition[v].end(); ++it){
            if (!visited[it->second]) {
                dfs(condition, it->second, visited);
            }
        }
    }

    void marked_fill(set<int> &term, map<int, map<char, vector<int>>> &condition_reverse, int n,
                     vector<vector<int>> &marked, set<char> &alphabet,
                     vector<int> &visited,
                     map<int, map<char, int>> condition) {
        queue<pair<int, int>> vertex;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((term.find(i) != term.end()) != (term.find(j) != term.end())) {
                    marked[i][j] = marked[j][i] = 1;
                    vertex.push(make_pair(i, j));
                }
            }
        }
        while (!vertex.empty()) {
            pair<int, int> v;
            v = vertex.front();
            vertex.pop();
            for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
                for (int i = 0; i < condition_reverse[v.first][*it].size(); i++){
                    int r = condition_reverse[v.first][*it][i];
                    for (int j = 0; j < condition_reverse[v.second][*it].size(); j++){
                        int s = condition_reverse[v.second][*it][j];
                        if (!marked[r][s]){
                            marked[r][s] = marked[s][r] = 1;
                            vertex.push(make_pair(r, s));
                        }
                    }
                }
            }
        }
    }

    void is_devil(map<int, map<char, vector<int>>> &condition_reverse, int v, vector<int> &devil) {
        devil[v] = 0;
        if (condition_reverse.find(v) != condition_reverse.end()) {
            for (auto it = condition_reverse[v].begin(); it != condition_reverse[v].end(); ++it) {
                for (int i = 0; i < (it->second).size(); i++) {
                    if (devil[(it->second)[i]]) {
                        is_devil(condition_reverse, (it->second)[i], devil);
                    }
                }
            }
        }
    }
}

int main() {
    std::ofstream out;
//    ifstream in("minimization.in");
//    out.open("minimization.out");
    ifstream in("in.txt");
    out.open("out.txt");
    int n, m, k, l;
    set<int> term;
    map<int, map<char, int>> condition;
    map<int, map<char, vector<int>>> condition_reverse;
    set<char> alphabet;
    in >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int terminal;
        in >> terminal;
        term.insert(terminal);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        in >> a >> b >> c;
        condition[a][c] = b;
        condition_reverse[b][c].push_back(a);
        alphabet.insert(c);
    }
    in.close();
    for (int i = 0; i < n + 1; i++){
        for (auto it = alphabet.begin(); it != alphabet.end(); ++it){
            if (condition.find(i) == condition.end()){
                condition[i][*it] = 0;
                condition_reverse[0][*it].push_back(i);
            } else{
                if (condition[i].find(*it) == condition[i].end()){
                    condition[i][*it] = 0;
                    condition_reverse[0][*it].push_back(i);
                }
            }
        }
    }
    vector<int> visited(n + 1, 0);
    vector<int> devil(n + 1, 1);
    for (auto it = term.begin(); it != term.end(); ++it) {
        is_devil(condition_reverse, *it, devil);
    }
    vector<vector<int>> marked(n + 1, vector<int>(n + 1, 0));
    dfs(condition, 1, visited);
    bool ok = false;
    for (auto it = term.begin(); it != term.end(); ++it) {
        if (visited[*it]) {
            ok = true;
        }
    }
    if (!ok) {
        out << 1 << " " << 0 << " " << 0;
        return 0;
    }
    marked_fill(term, condition_reverse, n + 1, marked, alphabet, visited, condition);
    vector<int> component(n + 1, -1);
    component[0] = 0;
    for (int i = 1; i < devil.size(); i++) {
        if (devil[i]) {
            component[i] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (!marked[1][i] && component[i] == -1) {
            component[i] = 1;
        }
    }
    int count = 1;
    for (int i = 2; i < n + 1; i++) {
        if (!visited[i]) {
            component[i] = 0;
            continue;
        }
        if (component[i] == -1) {
            count++;
            component[i] = count;
            for (int j = i + 1; j < n + 1; j++) {
                if (!marked[i][j]) {
                    component[j] = count;
                }
            }
        }
    }

//    for (int i = 0; i < visited.size(); i++) {
//        out << visited[i] << " ";
//    }
//    out << endl;
//    out << endl;
    for (int i = 0; i < marked.size(); i++) {
        for (int j = 0; j < marked[i].size(); j++) {
            out << marked[i][j] << " ";
        }
        out << endl;
    }
    out << endl;
//    for (int i = 0; i < devil.size(); i++) {
//        out << devil[i] << " ";
//    }
//    out << endl;

    map<int, map<char, int>> condition_min;
    set<int> term_min;
    set<int> count_v;

    for (int i = 0; i < component.size(); i++) {
        if (component[i] != 0) {
            count_v.insert(component[i]);
            if (term.find(i) != term.end()) {
                term_min.insert(component[i]);
            }
            if (condition.find(i) != condition.end()) {
                for (auto it = condition[i].begin(); it != condition[i].end(); ++it) {
                    if (component[it->second] != 0) {
                        condition_min[component[i]][it->first] = component[it->second];
                    }
                }
            }
        }
    }
    int count_transition = 0;
    for (auto it = condition_min.begin(); it != condition_min.end(); ++it) {
        count_transition += (it->second).size();
    }

    out << count_v.size() << " " << count_transition << " " << term_min.size() << "\n";

    for (auto it = term_min.begin(); it != term_min.end(); ++it) {
        out << *it << " ";
    }
    out << "\n";

    for (auto it = condition_min.begin(); it != condition_min.end(); ++it) {
        for (auto iter = (it->second).begin(); iter != (it->second).end(); ++iter) {
            out << it->first << " " << iter->second << " " << iter->first << "\n";
        }
    }
}

