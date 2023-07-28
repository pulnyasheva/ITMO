#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (int a, int b){
    std::cout << 1 << " " << a + 1 << " " << b + 1 << std::endl;
    string answer;
    cin >> answer;
    return answer == "YES";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> lamp(N, 0);
    for (int i = 0; i < N; i++){
        lamp[i] = i;
    }
    std::stable_sort(lamp.begin(), lamp.end(), comp);
    cout << 0 << " ";
    for (int i = 0; i < N; i++){
        cout << lamp[i] + 1 << " ";
    }
}
