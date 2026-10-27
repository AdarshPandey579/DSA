#include<iostream>
#include<vector>
using namespace std;

bool validPages(vector<int> arr, int n, int k, long long mid){
    int totalPages=0, totalStud=1;
    for(int i=0; i<n; i++){
        if(totalPages+arr[i]<=mid){
            totalPages+=arr[i];
            continue;
        }
        totalStud++;
        totalPages=arr[i];
    }
    return totalStud<=k;
}
int main(){
    vector<int> arr={12, 34, 67, 90};
    int k=2;
    int n=arr.size();
    if(n<k) return -1;
    long long st=0,end=0,mid;
    long long ans=-1;
    for(int pages : arr){
        st=max(st,(long long)pages);
        end+=pages;
    }
    while(st<=end){
        mid=st+(end-st)/2;
        if(validPages(arr, n, k, mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}