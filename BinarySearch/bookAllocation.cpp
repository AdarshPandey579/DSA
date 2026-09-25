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

bool isValid(vector<int>& arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for (int i=0; i<n; i++){
        if(arr[i] > mid){ // if any book has more pages than mid, it's not possible to allocate
            return false;
        }
        if(pageSum + arr[i] <= mid){ // if adding this book doesn't exceed mid, add it to current student's allocation
            pageSum += arr[i];
        }else{ // if adding this book exceeds mid, allocate to next student
            studentCount++;
            pageSum = arr[i];
        }
    }
    if(studentCount <= m){
        return true;
    }
    return false; // studentCount > m
}

int main(){
    vector<int> arr = {2,1,3,4};
    int m = 2, n = arr.size(), sum=0, st=0, end, ans=-1;
    end=Sum(arr);

    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    cout<<ans;
}

//g++ bookAllocation.cpp -o bookAllocation; ./bookAllocation