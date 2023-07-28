#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;
namespace {
    void is_eps(map<char, int> &eps, map<char, vector<string>> &conditions) {
        for (auto it = conditions.begin(); it != conditions.end(); ++it){
            if (!eps[it->first]){
                for (int i = 0; i < it->second.size(); i++){
                    string this_cond = it->second[i];
                    bool ch = true;
                    bool neterm = true;
                    for (int j = 0; j < this_cond.size(); j++) {
                        if (('a' <= this_cond[j]) && (this_cond[j] <= 'z')) {
                            ch = false;
                        } else if (!eps[this_cond[j]]){
                            neterm = false;
                        }
                    }
                    if (ch && neterm){
                        eps[it->first] = true;
                        is_eps(eps, conditions);
                    }
                }
            }
        }
    }
}

int main() {
    std::ofstream out;
    ifstream in("epsilon.in");
    out.open("epsilon.out");
    int n;
    char start;
    map<char, vector<string>> conditions;
    map<char, int> eps;
    string str;
    getline(in, str);
    n = std::stoi(str);
    start = str[2];
    for (int i = 0; i < n; i++) {
        getline(in, str);
        char neterm = str[0];
        string condition;
        if (str.size() > 4) {
            condition = str.substr(5, str.size());
            if (eps.find(neterm) == eps.end()) {
                eps[neterm] = false;
            }
        } else {
            eps[neterm] = true;
            continue;
        }
        conditions[neterm].push_back(condition);
    }
    in.close();
    is_eps(eps, conditions);
    for (auto it = eps.begin(); it != eps.end(); ++it) {
        if (it->second){
            out << it->first << " ";
        }
    }
}
