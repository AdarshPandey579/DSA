#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string prefix = "";
    for(int i=0; i<strs[0].size(); i++){
        char ch = strs[0][i];
        for(int j=1; j<strs.size(); j++){
            if(ch != strs[j][i] || i == strs[0].size()-1){
                cout<< prefix;
                return 0;
            }
        }
        prefix += ch;
    }
    cout<< prefix;
    return 0;
}