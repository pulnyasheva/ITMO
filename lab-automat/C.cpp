#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;
namespace {
    long long cnst = 1e9 + 7;
    void visited_fill(map<int, map<char, int>> &condition, int v, vector<int> &visited) {
        visited[v - 1] = 1;
        if (condition.find(v) != condition.end()){
            for (auto it = condition[v].begin(); it != condition[v].end(); ++it){
                if (!visited[it->second - 1]) {
                    visited_fill(condition, it->second, visited);
                }
            }
        }
    }
    void visited_term_fill(map<int, map<char, vector<int>>> &condition_reverse, int v, vector<int> &visited_term) {
        visited_term[v - 1] = 1;
        if (condition_reverse.find(v) != condition_reverse.end()){
            for (auto it = condition_reverse[v].begin(); it != condition_reverse[v].end(); ++it) {
                for (int i = 0; i < (it->second).size(); i++) {
                    if (!visited_term[(it->second)[i] - 1]) {
                        visited_term_fill(condition_reverse, (it->second)[i], visited_term);
                    }
                }
            }
        }
    }

//    bool is_infinity(vector<int> &visited, vector<int> &visited_term, vector<int> &inf, int v,
//                     map<int, set<int>> condition_one){
//        if (visited[0] && visited_term[0]){
//            inf[v - 1] = 1;
//        } else {
//            return false;
//        }
//        bool ok = false;
//        if (condition_one.find(v) != condition_one.end()){
//            for (auto it = condition_one[v].begin(); it != condition_one[v].end(); ++it){
//                if (visited[*it - 1] && visited_term[*it - 1]){
//                    if (inf[*it - 1] ){
//                        return true;
//                    }
//                    if (!inf[*it - 1]) {
//                        ok = ok || is_infinity(visited, visited_term, inf, *it, condition_one);
//                    }
//                }
//            }
//        }
//        return ok;
//    }
    bool is_infinity(vector<int> &visited, vector<int> &visited_term, vector<int> &inf, int v,
              map<int, set<int>> &condition_one) {
        inf[v - 1] = 1;
        if (condition_one.find(v) != condition_one.end()) {
            for (auto it = condition_one[v].begin(); it != condition_one[v].end(); ++it) {
                if (visited[*it - 1] && visited_term[*it - 1]){
                    if (inf[*it - 1] == 0) {
                        if (is_infinity(visited, visited_term, inf, *it, condition_one)) return true;
                    } else if (inf[*it - 1] == 1) {
                        return true;
                    }
                }
            }
        }
        inf[v - 1] = 2;
        return false;
    }

    long long count_term(int v, map<int, map<char, vector<int>>> &condition_reverse,
                   vector<int> &visited, vector<int> &visited_term){
        long long count = 0;
        if (visited[v - 1] && visited_term[v - 1]){
            if (v == 1){
                return 1;
            }
            if (condition_reverse.find(v) != condition_reverse.end()){
                for (auto it = condition_reverse[v].begin(); it != condition_reverse[v].end(); ++it) {
                    for (int i = 0; i < (it->second).size(); i++) {
                        count += count_term((it->second)[i], condition_reverse, visited, visited_term) % cnst;
                    }
                }
            }
        } else {
            return 0;
        }
        return count;
    }
}

int main() {
    std::ofstream out;
    ifstream in("problem3.in");
    out.open("problem3.out");
//    ifstream in("in.txt");
//    out.open("out.txt");
    int n, m, k;
    set<int> term;
    map<int, map<char, int>> condition;
    map<int, set<int>> condition_one;
    map<int, map<char, vector<int>>> condition_reverse;
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
        condition_one[a].insert(b);
        condition_reverse[b][c].push_back(a);
    }
    in.close();
    vector<int> visited(n, 0);
    vector<int> visited_term(n, 0);
    vector<int> inf(n, 0);
    visited_fill(condition, 1, visited);
    for (auto it = term.begin(); it != term.end(); ++it){
        if (visited[*it - 1]){
            visited_term_fill(condition_reverse, *it, visited_term);
        }
    }
    if (is_infinity(visited, visited_term, inf, 1, condition_one) && visited_term[0]){
        out << -1;
        return 0;
    } else {
        long long count = 0;
        for (auto it = term.begin(); it != term.end(); ++it){
            if (visited[*it - 1]){
                count += count_term(*it, condition_reverse, visited, visited_term);
            }
        }
        out << count % cnst;
        return 0;
    }
}
