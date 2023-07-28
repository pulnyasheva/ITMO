#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

namespace {
    bool equivalence(set<int> &term_1,
                     set<int> &term_2,
                     map<int, vector<pair<int, char>>> &condition_1,
                     map<int, vector<pair<int, char>>> &condition_2,
                     vector<vector<int>> &visited){
        queue<pair<int, int>> vertex;
        vertex.push(make_pair(1, 1));
        while (!vertex.empty()){
            pair<int, int> v;
            v = vertex.front();
            vertex.pop();
            if ((term_1.find(v.first) != term_1.end()) != (term_2.find(v.second) != term_2.end())){
                return false;
            }
            visited[v.first][v.second] = 1;
            vector<int> visit;
            if (v.second != 0 && condition_2.find(v.second) != condition_2.end()){
                visit.resize(condition_2[v.second].size());
            }
            if (v.first != 0 && condition_1.find(v.first) != condition_1.end()) {
                for (int i = 0; i < condition_1[v.first].size(); i++) {
                    int next_v_1 = condition_1[v.first][i].first;
                    int next_v_2 = 0;
                    if (v.second != 0 && condition_2.find(v.second) != condition_2.end()) {
                        for (int j = 0; j < condition_2[v.second].size(); j++) {
                            if (condition_1[v.first][i].second == condition_2[v.second][j].second) {
                                next_v_2 = condition_2[v.second][j].first;
                                visit[j] = 1;
                            }
                        }
                    }
                    if (visited[next_v_1][next_v_2] != 1) {
                        vertex.push(make_pair(next_v_1, next_v_2));
                    }
                }
            }
            if (v.second != 0 && condition_2.find(v.second) != condition_2.end()) {
                for (int i = 0; i < condition_2[v.second].size(); i++) {
                    if (!visit[i]) {
                        int next_v_2 = condition_2[v.second][i].first;
                        int next_v_1 = 0;
                        if (v.first != 0 && condition_1.find(v.first) != condition_1.end()) {
                            for (int j = 0; j < condition_1[v.second].size(); j++) {
                                if (condition_2[v.second][i].second == condition_1[v.first][j].second) {
                                    next_v_1 = condition_1[v.first][j].first;
                                }
                            }
                        }
                        if (visited[next_v_1][next_v_2] != 1) {
                            vertex.push(make_pair(next_v_1, next_v_2));
                        }
                    }
                }
            }
        }
        return true;
    }
}

int main() {
    std::ofstream out;
    ifstream in("equivalence.in");
    out.open("equivalence.out");
//    ifstream in("C:\\Users\\pulaa\\CLionProjects\\laba_avtomat\\in.txt");
//    out.open("C:\\Users\\pulaa\\CLionProjects\\laba_avtomat\\out.txt");
    int n_1, m_1, k_1, n_2, m_2, k_2;
    set<int> term_1, term_2;
    map<int, vector<pair<int, char>>> condition_1, condition_2;
    in >> n_1 >> m_1 >> k_1;
    for (int i = 0; i < k_1; i++) {
        int terminal;
        in >> terminal;
        term_1.insert(terminal);
    }
    for (int i = 0; i < m_1; i++) {
        int a, b;
        char c;
        in >> a >> b >> c;
        condition_1[a].push_back(make_pair(b, c));
    }
    in >> n_2 >> m_2 >> k_2;
    for (int i = 0; i < k_2; i++) {
        int terminal;
        in >> terminal;
        term_2.insert(terminal);
    }
    for (int i = 0; i < m_2; i++) {
        int a, b;
        char c;
        in >> a >> b >> c;
        condition_2[a].push_back(make_pair(b, c));
    }
    in.close();
    vector<vector<int>> visited(n_1 + 1, vector<int> (n_2 + 1, 0));
    if (equivalence(term_1, term_2, condition_1, condition_2, visited)){
        out << "YES";
    } else {
        out << "NO";
    }
}






