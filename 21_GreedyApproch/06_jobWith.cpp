#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Job{
    public:
        int idx;
        int deadline;
        int profit;

        Job(int idx,int deadline,int profit){
            this->idx=idx;
            this->deadline=deadline;
            this->profit=profit;
        }
};

int maxProfit(vector<pair<int,int>>pairs){
    int n= pairs.size();
    vector<Job> jobs;

    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b) {//empty list is called capture ;ist ==>lambda function
        return a.profit>b.profit;
    });//descending order sort
    cout<<"Selecting Job"<<jobs[0].idx<<endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;
    for(int i =1;i<n;i++){
        if(jobs[i].deadline>=safeDeadline){
            cout<<"Selecting job"<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            safeDeadline++;
        }
    }
    cout<<"Max Profit ="<<profit<<endl;
    return profit;
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