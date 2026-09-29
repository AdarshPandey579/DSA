#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    int minlen=INT_MAX, low=0, high=0, sum=0, n=nums.size();
    while(high<n){
        sum+=nums[high];
        while(sum>=target){
            int len=high-low+1;
            minlen=min(minlen,len);
            sum=sum-nums[low];
            low++;
        }
        high++;
    }
    if(minlen==INT_MAX){
        cout<< 0;
    }
    cout<< minlen;
    return 0;
}