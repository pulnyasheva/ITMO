#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    std::ofstream out;
    ifstream in("problem5.in");
    out.open("problem5.out");
//    ifstream in("C:\\Users\\pulaa\\CLionProjects\\laba_avtomat\\in.txt");
//    out.open("C:\\Users\\pulaa\\CLionProjects\\laba_avtomat\\out.txt");
    int n, m, k, l;
    set<int> term;
    set<char> alphabet;
    map<int, vector<pair<int, char>>> condition;
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
        condition[a].push_back(make_pair(b, c));
        alphabet.insert(c);
    }
    in.close();

    map<int, vector<pair<int, char>>> condition_dka;
    set<int> term_dka;
    vector<set<int>> p = {{1}};
    vector<set<int>> q = {{1}};
    set<int> pd;
    set<int> qd;
    if (term.find(1) != term.end()){
        term_dka.insert(1);
    }
    while (!p.empty()){
        pd = p[p.size() - 1];
        p.pop_back();
        for (std::set<char>::iterator it = alphabet.begin(); it != alphabet.end(); ++it){
            qd.clear();
            bool is_term = false;
           for (std::set<int>::iterator iter = pd.begin(); iter != pd.end(); ++iter){
               for (int j = 0; j < condition[*iter].size(); j++){
                   if (condition[*iter][j].second == *it){
                       qd.insert(condition[*iter][j].first);
                       if (term.find(condition[*iter][j].first) != term.end()){
                           is_term = true;
                       }
                   }
               }
           }
           int index_qd = -1;
           int index_pd = -1;
           for (int i = 0; i < q.size(); i++){
               if (q[i] == qd){
                   index_qd = i;
               }
           }
            for (int i = 0; i < q.size(); i++){
                if (q[i] == pd){
                    index_pd = i;
                }
            }
           if (index_qd == -1){
               p.push_back(qd);
               q.push_back(qd);
               index_qd = q.size() - 1;
           }
           if (is_term){
               term_dka.insert(index_qd + 1);
           }
           condition_dka[index_pd + 1].push_back(make_pair(index_qd + 1, *it));
        }
    }
//
//    int count = 0;
//    for (int i = 0; i < condition_dka.size(); i++){
//        count += condition_dka[i].size();
//    }
//
//    out << q.size() << " " << count << " " << term_dka.size() << endl;
//    for (std::set<int>::iterator it = term_dka.begin(); it != term_dka.end(); ++it){
//        out << *it << " ";
//    }
//    out << endl;
//    for (auto it = condition_dka.begin(); it != condition_dka.end(); ++it){
//        for (int i = 0; i < (it->second).size(); i++){
//            out << it->first << " " << (it->second)[i].first << " " << (it->second)[i].second << endl;
//        }
//    }
    long long cnst = 1e9 + 7;
    vector<long long> count(q.size());
    count[0] = 1;
    vector<long long> changeable;
    for (int i = 0; i < l; i++){
        changeable.clear();
        changeable.resize(q.size());
        for (auto it = condition_dka.begin(); it != condition_dka.end(); ++it) {
            for (int j = 0; j < (it->second).size(); j++) {
                changeable[(it->second)[j].first - 1] += count[it->first - 1] % cnst;
            }
        }
        count = changeable;
    }
    long long answer = 0;
    for (std::set<int>::iterator it = term_dka.begin(); it != term_dka.end(); ++it) {
        answer += count[*it - 1] % cnst;
    }
    out << answer % cnst;
    return 0;
}


