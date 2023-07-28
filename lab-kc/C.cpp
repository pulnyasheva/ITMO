#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;
namespace {
    void is_generative(map<char, bool> &generative, map<char, vector<string>> &conditions) {
        for (auto it = conditions.begin(); it != conditions.end(); ++it) {
            if (!generative[it->first]) {
                for (int i = 0; i < it->second.size(); i++) {
                    string this_cond = it->second[i];
                    bool neterm = true;
                    for (int j = 0; j < this_cond.size(); j++) {
                        if (('A' <= this_cond[j]) && (this_cond[j] <= 'Z')) {
                            if (!generative[this_cond[j]]) {
                                neterm = false;
                            }
                        }
                    }
                    if (neterm) {
                        generative[it->first] = true;
                        is_generative(generative, conditions);
                    }
                }
            }
        }
    }

    void delete_generate(map<char, bool> &generative, map<char, vector<string>> &conditions){
        for (auto it = conditions.begin(); it != conditions.end(); ) {
            if (!generative[it->first]) {
                it = conditions.erase(it);
            } else {
                for (auto iter = it->second.begin(); iter != it->second.end(); ) {
                    string this_cond = *iter;
                    bool del = false;
                    for (int j = 0; j < this_cond.size(); j++) {
                        if (('A' <= this_cond[j]) && (this_cond[j] <= 'Z')) {
                            if (!generative[this_cond[j]]) {
                                del = true;
                            }
                        }
                    }
                    if (del){
                        iter = it->second.erase(iter);
                    } else {
                        ++iter;
                    }
                }
                ++it;
            }
        }
    }

    void is_achievable(map<char, bool> &achievable, map<char, vector<string>> &conditions) {
        for (auto it = conditions.begin(); it != conditions.end(); ++it) {
            if (achievable[it->first]) {
                for (int i = 0; i < it->second.size(); i++) {
                    string this_cond = it->second[i];
                    for (int j = 0; j < this_cond.size(); j++) {
                        if (('A' <= this_cond[j]) && (this_cond[j] <= 'Z')) {
                            if (!achievable[this_cond[j]]) {
                                achievable[this_cond[j]] = true;
                                is_achievable(achievable, conditions);
                            }
                        }
                    }
                }
            }
        }
    }

    void delete_achievable(map<char, bool> &achievable, map<char, vector<string>> &conditions) {
        for (auto it = conditions.begin(); it != conditions.end(); ) {
            if (!achievable[it->first]) {
                it = conditions.erase(it);
            } else {
                ++it;
            }
        }
    }
}

int main() {
    std::ofstream out;
    ifstream in("useless.in");
    out.open("useless.out");
    int n;
    char start;
    map<char, vector<string>> conditions;
    map<char, bool> generative;
    map<char, bool> achievable;
    set<char> useless;
    string str;
    getline(in, str);
    n = std::stoi(str);
    start = str[str.size() - 1];
    achievable[start] = true;
    generative[start] = false;
    useless.insert(start);
    for (int i = 0; i < n; i++) {
        getline(in, str);
        char neterm = str[0];
        string condition;
        if (str.size() > 4) {
            condition = str.substr(5, str.size());
        } else {
            condition = "*";
            generative[neterm] = true;
            achievable[neterm] = false;
        }
        bool ch = true;
        for (int i = 0; i < condition.size(); i++) {
            if (('A' <= condition[i]) && (condition[i] <= 'Z')) {
                if (generative.find(condition[i]) == generative.end()) {
                    generative[condition[i]] = false;
                }
                if (achievable.find(condition[i]) == achievable.end()) {
                    achievable[condition[i]] = false;
                }
                useless.insert(condition[i]);
                ch = false;
            }
        }
        if (ch) {
            generative[neterm] = true;
        }
        conditions[neterm].push_back(condition);
        useless.insert(neterm);
        if (generative.find(neterm) == generative.end()) {
            generative[neterm] = false;
        }
        if (achievable.find(neterm) == achievable.end()) {
            achievable[neterm] = false;
        }
    }
    in.close();
    is_generative(generative, conditions);
    delete_generate(generative, conditions);
    is_achievable(achievable, conditions);
    delete_achievable(achievable, conditions);
    for (auto it = useless.begin(); it != useless.end(); ++it) {
        if (conditions.find(*it) == conditions.end()){
            out << *it << " ";
        }
    }
}
