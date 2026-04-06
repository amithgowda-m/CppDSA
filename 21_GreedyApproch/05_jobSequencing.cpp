#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int>p2){
    return p1.second>p2.second;//descending order sorting
}
void maxProfit(vector<pair<int,int>>job){
    sort(job.begin(),job.end(),compare);//begin and end --> first and second 
    int profit = job[0].second;
    int safeDeadline=2;

    for(int i=1;i<job.size();i++){
        if(job[i].first>=safeDeadline){
            profit+=job[i].second;
            safeDeadline++;
        }
    }
    cout<<"Max profit from jobs: "<<profit<<endl; 
}
int main(){
    vector<pair<int,int>> job(4,make_pair(0,0));
    job[0]=make_pair(4,20);
    job[1]=make_pair(1,10);
    job[2]=make_pair(1,40);
    job[3]=make_pair(1,30);

    maxProfit(job);

    return 0;
}