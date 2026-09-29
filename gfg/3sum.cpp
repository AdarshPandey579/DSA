#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {-2, 0, 1, 3};
    int  target=2;
    sort(arr.begin(),arr.end());
    int ans=0, n=arr.size();
    for (int i=0; i<n-2; i++){
        int x=i+1, y=n-1, sum=0;
        while(x<y){
            sum=arr[i]+arr[x]+arr[y];
            if(sum>=target){
                y--;
            }else{
                ans+=y-x;
                x++;
            }
        }
    }
    cout<< ans;
    return 0;
}