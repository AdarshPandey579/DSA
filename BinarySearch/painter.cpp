#include<iostream>
#include<vector>
using namespace std;

int Sum(vector<int>& arr){
    int sum = 0;
    for (int i=0; i<arr.size(); i++){
        sum+=arr[i];
    }
    return sum;
}

bool isPossible(vector<int>& arr, int n, int m, int mid){
    int painterCount = 1;
    int timeSum = 0;
    for (int i=0; i<n; i++){
        if(arr[i] > mid){ // if any board has more time than mid, it's not possible to allocate
            return false;
        }
        if(timeSum + arr[i] <= mid){ // if adding this board doesn't exceed mid, add it to current painter's allocation
            timeSum += arr[i];
        }else{ // if adding this board exceeds mid, allocate to next painter
            painterCount++;
            timeSum = arr[i];
        }
    }
    if(painterCount <= m){
        return true;
    }
    return false; // painterCount > m
}

int main(){
    vector<int> arr = {40,30,10,20};
    int m = 2, n = arr.size(), sum=0, st=0, end, ans=-1;
    end=Sum(arr);
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    cout<<ans;
}

//g++ painter.cpp -o painter; ./painter 