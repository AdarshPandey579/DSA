#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    double maxAvg=INT_MIN;
    double sum=0, i=0;
    while(i<k){
        sum+=nums[i];
        i++;
    }
    maxAvg=max(maxAvg,sum/k);
    while(i<nums.size()){
        sum=sum+nums[i]-nums[i-k];
        maxAvg=max(maxAvg,sum/k);
        i++;
    }
    cout << maxAvg;
    return 0;
}