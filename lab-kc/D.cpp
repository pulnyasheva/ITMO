#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    long long cnst = 1e9 + 7;
    std::ofstream out;
    ifstream in("nfc.in");
    out.open("nfc.out");
    int n;
    char start;
    map<char, set<string>> conditions;
    string str;
    string word;
    getline(in, str);
    set<char> neterms;
    map<char, vector<vector<long long >>> count;
    n = std::stoi(str);
    start = str[str.size() - 1];
    neterms.insert(start);
    for (int i = 0; i < n; i++) {
        getline(in, str);
        char neterm = str[0];
        string condition;
        condition = str.substr(5, str.size());
        for (int j = 0; j < condition.size(); j++) {
            if (('A' <= condition[j]) && (condition[j] <= 'Z')) {
                neterms.insert(condition[j]);
            }
        }
        conditions[neterm].insert(condition);
        neterms.insert(neterm);
    }
    getline(in, word);
    in.close();
    for (auto it = neterms.begin(); it != neterms.end(); ++it) {
        vector<vector<long long>> vec(word.size(), vector<long long>(word.size(), 0));
        count[*it] = vec;
    }

    for (auto it = conditions.begin(); it != conditions.end(); ++it) {
        for (auto iter = it->second.begin(); iter != it->second.end(); ++iter) {
            if ((*iter).size() == 1) {
                for (int j = 0; j < word.size(); j++) {
                    if (word[j] == (*iter)[0]) {
                        count[it->first][j][j] = 1;
                    }
                }
            }
        }
    }

    for (int m = 1; m < word.size(); m++) {
        for (auto it = conditions.begin(); it != conditions.end(); ++it) {
            for (auto iter = it->second.begin(); iter != it->second.end(); ++iter) {
                if ((*iter).size() == 2) {
                    for (int i = 0; i < word.size() - m; i++) {
                        for (int j = i; j < i + m; j++) {
                            count[it->first][i][i + m] +=
                                    (count[(*iter)[0]][i][j] * count[(*iter)[1]][j + 1][i + m]) % cnst;
                            count[it->first][i][i + m] %= cnst;
                        }
                    }
                }
            }
        }
    }

    out << count[start][0][word.size() - 1] % cnst;
}
