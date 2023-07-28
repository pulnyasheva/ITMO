#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

namespace {
    bool isomorphism(set<int> &term_1,
                     set<int> &term_2,
                     map<int, vector<pair<int, char>>> &condition_1,
                     map<int, vector<pair<int, char>>> &condition_2, int &v_1, int &v_2,
                     vector<int> &visited, vector<int> &bijection){
        visited[v_1 - 1] = 1;
        if ((term_1.find(v_1) != term_1.end()) != (term_2.find(v_2) != term_2.end())){
            return false;
        }
        bijection[v_1 - 1] = v_2;
        bool result = true;
        if (condition_1[v_1].size() != condition_2[v_2].size()){
            return false;
        }
        for (int i = 0; i < condition_1[v_1].size(); i++){
            int next_v_1 = condition_1[v_1][i].first;
            int next_v_2 = 0;
            bool ok = false;
            for (int j = 0; j < condition_2[v_2].size(); j++){
                if (condition_1[v_1][i].second == condition_2[v_2][j].second){
                    next_v_2 = condition_2[v_2][j].first;
                    ok = true;
                }
            }
            if (!ok){
                return false;
            }
            if (condition_1[next_v_1].size() != condition_2[next_v_2].size()){
                return false;
            }
            if (visited[next_v_1 - 1]){
                result = result && next_v_2 == bijection[next_v_1 - 1];
            } else {
                result = result && isomorphism(term_1, term_2,
                                               condition_1, condition_2,next_v_1, next_v_2,
                                               visited, bijection);
            }
        }
        return result;
    }
}

int main() {
    std::ofstream out;
    ifstream in("isomorphism.in");
    out.open("isomorphism.out");
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
    if (!(n_1 == n_2 && m_1 == m_2 && k_1 == k_2)){
        out << "NO";
        return 0;
    }
    vector<int> visited(n_1);
    vector<int> bijection(n_1);
    int v_1 = 1;
    int v_2 = 1;
    if (isomorphism(term_1, term_2,condition_1, condition_2, v_1, v_2, visited, bijection)){
        out << "YES";
    } else {
        out << "NO";
    }
}




