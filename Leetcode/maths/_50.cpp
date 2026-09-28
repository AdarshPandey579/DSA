#include<iostream>
using namespace std;

int main(){
    double x=2;
    int n=-2;
    if( n==0 ) return 1.0;
    if( x==1 ) return 1.0;
    if( x==0 ) return 0;
    if( x==-1 && n%2==0 ) return 1;
    if( x==-1 && n%2!=0 ) return -1;
    if( n==1 ) return x;
    double ans = 1;
    long Binary = n; 
    if( n<0 ){
        x = 1/x;
        Binary = -Binary;
    }
    while( Binary>0 ){
        if( Binary%2==1 ){
            ans*=x;
        }
        x*=x;
        Binary/=2;
    }
    cout<<ans;
    return 0;
}
