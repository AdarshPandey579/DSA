#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval={4,8};
    vector<vector<int>> modified;
    int n=intervals.size();
    bool insert=false;
    for(auto interval : intervals){
        if(newInterval[0]<=interval[0] && insert==false){
            modified.push_back(newInterval);
            insert=true;
        }
        modified.push_back(interval);
    }
    if(insert==false) modified.push_back(newInterval);

    intervals.clear();

    int s1=modified[0][0], e1=modified[0][1];
    for(int i=1;i<modified.size();i++){
        int s2=modified[i][0], e2=modified[i][1];
        if(e1>=s2){
            e1=max(e1,e2);
            continue;
        }
        intervals.push_back({s1,e1});
        s1=s2;
        e1=e2;
    }
    intervals.push_back({s1,e1});

    for(auto interval : intervals){
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}

//g++ _57.cpp -o _57;./_57  
