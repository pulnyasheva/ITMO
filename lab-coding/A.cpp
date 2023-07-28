#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> arr(n, vector<long long>(2, 0));
    vector<long long> ch(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        arr[i][1] = i;
        ch[i] = arr[i][0];
    }
    vector<int> bits(n, 0);
    while (arr.size() > 1) {
        long long min1 = LONG_LONG_MAX;
        long long min2 = LONG_LONG_MAX;
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] < min1) {
                min2 = min1;
                min1 = arr[i][0];
                index2 = index1;
                index1 = i;
            } else {
                if (arr[i][0] < min2) {
                    min2 = arr[i][0];
                    index2 = i;
                }
            }
        }
        long long sum = min1 + min2;
        vector<long long> thisElement(arr[index1].size() + arr[index2].size() - 1, 0);
        thisElement[0] = sum;
        int j = 1;
        while (j < thisElement.size()) {
            while (j < arr[index1].size()) {
                thisElement[j] = arr[index1][j];
                bits[arr[index1][j]]++;
                j++;
            }
            thisElement[j] = arr[index2][j - arr[index1].size() + 1];
            bits[arr[index2][j - arr[index1].size() + 1]]++;
            j++;
        }
        if (index1 > index2) {
            arr.erase(arr.begin() + index1);
            arr.erase(arr.begin() + index2);
        } else {
            arr.erase(arr.begin() + index2);
            arr.erase(arr.begin() + index1);
        }
        arr.push_back(thisElement);
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer = answer + bits[i] * ch[i];
    }
    cout << answer;
}
