#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car{
    public:
        int idx;
        int distSq;

        Car(int idx,int distSq){
            this->idx=idx;
            this->distSq = distSq;
        }

        bool operator < (const Car &obj) const{
            return this->distSq > obj.distSq;//for min heap
        }

};

void nearbyCars(vector<pair<int,int>>pos,int k){
    //index,distanceSquare for each car from origin 
    vector<Car> cars;

    for(int i=0;i<pos.size();i++){//O(n)
        int distSq= pos[i].first*pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i,distSq));
    }

    priority_queue<Car> pq(cars.begin(),cars.end());//O(n)

    // for(int i=0;i<cars.size();i++){//O(nlogn)
    //     pq.push(cars[i]);
    // } this is time intensive

    for(int i=0;i<k;i++){//O(Klogn+n)
        cout<<"Car "<<pq.top().idx<<endl;
        pq.pop();//O(logn) is time complexity
    }

}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4)) ;
    int k=2;

    nearbyCars(pos,k);
    return 0;

}