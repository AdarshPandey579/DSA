#include <iostream>
using namespace std;

int main(){
    int num = 14;
    int step=0;
    while(num!=0){
        if((num&1)==0) num/=2;
        else num-=1;
        step+=1;
    }
    cout << step;
    return 0;
}

//g++ _1342.cpp -o _1342;./_1342