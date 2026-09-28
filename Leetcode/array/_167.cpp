#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans;
    int n=nums.size();
    int x=0, y=n-1;
    while(x<y){
        if(nums[x]+nums[y]<target) x++;
        else if(nums[x]+nums[y]>target) y--;
        else {
            ans.push_back(x);
            ans.push_back(y);
            break;
        }
    }
    cout<<"Index are :";
    for(int num : ans) cout<<num<<" ";
    return 0;
}