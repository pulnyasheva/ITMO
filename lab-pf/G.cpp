#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string expr;
int index = 0;
vector<long long> b;

long long cnk(long long n, long long k){
    long long result = 1;
    long long factK = 1;
    for (long long i = n - k + 1; i <= n; i++){
        result = result * i;
    }
    for (long long i = 2; i <= k; i++){
        factK = factK * i;
    }
    result = result / factK ;
    return result;
}

vector<long long> parse(){
    vector<long long> expr1(7, 0);
    vector<long long> expr2(7, 0);
    vector<long long> worker(7, 0);
    if (expr[index] == 'B'){
        if (index < expr.size()){
            index += 1;
        }
        return b;
    } else if (expr[index] == 'L'){
        index += 2;
        expr1 = parse();
        index += 1;
        worker[0] = 1;
        for (int i = 1; i < 7; i++){
            for (int j = 1; j <= i; j++){
                worker[i] += worker[i - j] * expr1[j];
            }
        }
        return worker;
    } else if (expr[index] == 'P'){
        index += 2;
        expr1 = parse();
        index += 1;
        expr2 = parse();
        index += 1;
        for (int i = 0; i < 7; i++){
            for (int j = 0; j <= i; j++){
                worker[i] += expr1[j] * expr2[i - j];
            }
        }
        return worker;
    } else if (expr[index] == 'S'){
        index += 2;
        expr1 = parse();
        index += 1;
        vector<vector<long long>> m(7, vector<long long>(7, 0));
        for (int i = 0; i < 7; i++){
            m[0][i] = 1;
        }
        for (int i = 1; i < 7; i++){
            for (int j = 1; j < 7; j++){
                for (int k = 0; k <= i / j; k++){
                    m[i][j] += cnk(expr1[j] + k - 1, k) * m[i - j * k][j - 1];
                }
            }
        }
        for (int i = 0; i < 7; i++){
            worker[i] = m[i][i];
        }
        return worker;
    }
    return worker;
}


int main() {
    cin >> expr;
    b.resize(7, 0);
    b[1] = 1;
    vector<long long> answer = parse();
    for (long long w : answer){
        cout << w << " ";
    }
}
