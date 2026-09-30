#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s="ccbbcc";
    unordered_map<char, int> m;
    int low = 0;
    int result = 0;
    for (int high = 0; high < s.size(); high++) {
        if (m.find(s[high]) != m.end()) { // check s[high] present in map
            low = max(low,m[s[high]]) + 1; // assure new low don't move back , always move forward
        }
        m[s[high]] = high;
        result = max(result, high - low + 1);
    }
    cout<< result;
    return 0;
}