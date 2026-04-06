#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxActivities(vector<int> start,vector<int>end){
    //sort on end time
    //A0 select
    cout<<"selecting A0\n";
    int count =1;
    int curEndTime=end[0];

    for(int i=1;i<end.size();i++){
        if(start[i]>=curEndTime){
            cout<<"selecting A"<<i<<endl;
            count++;
            curEndTime=end[i];
        }
    }
    return count;
}
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;//ascending order
}

int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    cout<<maxActivities(start,end)<<endl;
    vector<pair<int,int>> activity(3,make_pair(0,0));
    activity[0]=make_pair(0,9);
    activity[1]=make_pair(1,2);
    activity[2]=make_pair(2,4);

    for(int i=0;i<activity.size();i++){
        cout<<"A"<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    }
    sort(activity.begin(),activity.end(),compare);
    cout<<"---------sorted---------\n";
    for(int i=0;i<activity.size();i++){
        cout<<"A"<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    }
    return 0;
}