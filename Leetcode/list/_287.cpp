#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,3,4,2,2};
    int s=0,f=0;
    while(true){
        s=nums[s];
        f=nums[nums[f]];
        if(s==f){  // cycle detected
            s=0;
            while(s!=f){  // find the entrance of the cycle
                s=nums[s];
                f=nums[f];
            }
            cout<<s;
            break;
        }
    }
    return 0;
}