#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;


int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int minDiff=INT_MAX, diff, result, sum;
    for (int i=0; i<n-2; i++){
        int x=i+1, y=n-1;
        while(x<y){
            sum=nums[i]+nums[x]+nums[y];
            diff=abs(sum-target);
            if(diff<minDiff){
                minDiff=diff;
                result=sum;
            }
            if(sum > target) y--;
            else if(sum < target) x++;
            else cout<< result;
        }
    }
    cout<< result;
    return 0;
}