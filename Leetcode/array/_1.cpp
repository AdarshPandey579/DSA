#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums={3,2,4};
    int target=6;
    vector<int> ans;
    unordered_map<int,int> m;
    int n=nums.size(), x, y;
    for(int i=0; i<n; i++){
        x=nums[i];
        y=target-x;
        if(m.find(y)!=m.end()){
            ans.push_back(m[y]);
            ans.push_back(i);
            break;
        }
        m[x]=i;
    }
    for(int num : ans) cout<<num<<" ";
    return 0;
}