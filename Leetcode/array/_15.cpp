#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>> ans;
    for(int i=0; i<n-2; i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int x=i+1, y=n-1;
        int target = -nums[i];
        while(x<y){
            if(nums[x]+nums[y]<target) x++;
            else if(nums[x]+nums[y]>target) y--;
            else{
                ans.push_back({nums[i],nums[x],nums[y]});
                x++;
                y--;
                while(x<y && nums[x]==nums[x-1]){
                    x++;
                }
                // while(x<y && nums[y]==nums[y+1]){
                //     y--;
                // }
            }
        }
    }
    for(auto a : ans){
        for(auto b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}