#include <iostream>
using namespace std;

void waterTrapped(int *heights,int n){
    int rightMax[100],leftMax[100];
    // int mini[100];
    rightMax[n-1]=heights[n-1] ;
    leftMax[0]=heights[0];   

    for (int i = 1; i < n; i++)
    {
        leftMax[i]=max(leftMax[i-1],heights[i-1]);
    }
    for (int i = n-2; i >=0 ; i--)
    {
        rightMax[i]=max(rightMax[i+1],heights[i+1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     mini[i]=min(leftMax[i],rightMax[i]);//min - height = waterr trapperrd
    // }
    int waterTrapped=0;
    int curWater=0;
    for (int i = 0; i < n; i++)//O(n)
    {
        curWater=min(leftMax[i],rightMax[i])-heights[i];
        if (curWater>0)
        {
            waterTrapped+=curWater;
        }
        
    }
    cout<<waterTrapped;
} 

int main(){
    int heights[7]={4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);
    waterTrapped(heights,n);
    return 0;
}