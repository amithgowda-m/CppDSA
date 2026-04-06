#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void indianCoins(vector<int> coins, int val){
    sort(coins.begin(), coins.end(), greater<int>()); // largest first
    
    int ans = 0;
    cout << "Coins used: ";
    
    for(int coin : coins){//O(n)--  without sorting and O(nlogn) -->with 
        if(val >= coin){
            int count = val / coin;     // how many times coin fits so we divide
            ans += count;
            val = val% (coin);      //val-=coin*count reduce the amount

            while(count--) cout << coin << " ";
        }
    }
    cout << "\nTotal coins used = " << ans << endl;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    indianCoins(coins, 121);
    return 0;
}
