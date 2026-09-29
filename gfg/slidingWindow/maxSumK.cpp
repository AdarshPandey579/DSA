#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {100, 200, 300, 400};
    int k=2;
    int low=0, high=k-1 , n=arr.size(), maxSum=0, sum=0;
    for (int i=low; i<=high; i++){
        sum+=arr[i];
    }
    maxSum=sum;
    while(high<n-1){
        sum=sum-arr[low]+arr[high+1];
        maxSum=max(maxSum,sum);
        low++;
        high++;
    }
    cout<< maxSum;
    return 0;
}