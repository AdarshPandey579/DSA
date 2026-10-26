#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int left=-1, right=-1, n=arr.size();
    int st=0, end=n-1, mid;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==target){
            left=mid;
            end=mid-1;
        }else if(arr[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    st=0, end=n-1;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==target){
            right=mid;
            st=mid+1;
        }else if(arr[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout<<left<<" "<<right<<endl;
    return 0;
}