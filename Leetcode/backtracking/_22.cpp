#include<iostream>
#include<vector>
using namespace std;

void func(string& digits, int idx, string letters[], string& tmp, vector<string>& ans){
    if(idx == digits.size()){
        ans.push_back(tmp);
        return;
    }
    int num = digits[idx]-'0';

    for(char letter : letters[num]){
        tmp.push_back(letter);
        func(digits, idx+1, letters, tmp, ans);
        tmp.pop_back();
    }
    return;
}

int main(){
    string digits = "23";
    string tmp="";
    vector<string> ans;
    string letters[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int idx=0;

    func(digits, idx, letters, tmp, ans);

    for(string str : ans){
        cout<<str<<endl;
    }

    return 0;
}