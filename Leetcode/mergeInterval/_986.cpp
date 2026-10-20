#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> a = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> b = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> result;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while (i < n && j < m) {
        int s1 = a[i][0];
        int e1 = a[i][1];
        int s2 = b[j][0];
        int e2 = b[j][1];

        int s = max(s1, s2);
        int e = min(e1, e2);

        if (s <= e) {
            result.push_back({s, e});
        }

        if (e1 <= e2) {
            i++;
        } else {
            j++;
        }
    }

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}

// g++ _986.cpp -o _986;./_986