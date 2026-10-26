#include <iostream>
#include <vector>
using namespace std;

bool validSpeed(vector<int>& arr, int n, int h, int mid){
    long long totalHours=0;
    for(int i=0; i<n; i++){
        totalHours+=(arr[i]/mid);
        if(arr[i]%mid!=0){
            totalHours+=1;
        }
    }
    if(totalHours>h) return false;
    return true;
}

int main(){
    vector<int> piles = {30,11,23,4,20};
    // int h = 5;
    int h = 8;
    int st=1, end, mid, n=piles.size();
    for(int banana : piles){
        end=max(end,banana);
    }
    
    long long ans;
    while(st<=end){
        mid=st+(end-st)/2;
        if(validSpeed(piles, n, h, mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}