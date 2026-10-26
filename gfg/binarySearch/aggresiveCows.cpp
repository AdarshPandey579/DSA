#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool validDiff(vector<int>& arr, int k, int n, int mid){
    int totalCows=1;
    int prevCow=arr[0];
    for(int i=1; i<n; i++){
        int diff=arr[i]-prevCow;
        if(diff<mid) continue;
        totalCows++;
        prevCow=arr[i];
    }
    if(totalCows>=k) return true;
    return false;
}

int main(){
    vector<int> arr={1,2,4,8,9};
    int k = 3;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int st=1, end=arr[n-1]-arr[0], ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(validDiff(arr, k, n, mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}