#include<iostream>
using namespace std;

int main(){
    double x=2, ans=1;
    int BF=10;
    while(BF>0){
        cout<<BF<<" ";
        if(BF%2==1){
            ans*=x;
        }
        x*=x;
        BF/=2;
    }
    cout<<endl<<ans;
}
