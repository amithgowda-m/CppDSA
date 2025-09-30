// row wise column wise sorted matrix of order 2 cross 2
// 1 st approach bruteforce -- go to each cell adn search for key TC = O(n*m);
// 2nd approach - row wise or column wise binary search (based on which is small)
// binary search per row TC=O(logm)--best and worst case for colum n , row m  //
// total = O(nlogm)
// if they have mentioned in question that it is sorted row wise or column wise or both then this approach is best because we are using their hint
// they have given sateek informtion to solve question effficiently

// 3 rd approach stair case search

#include <iostream>
using namespace std;

void bruteForce(int arr[][5], int m, int n, int key)
{ // O(m*n)

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
            {
                cout << "Key " << key << " Found at row " << i + 1 << " column" << j + 1;
            }
        }
    }
}

bool step(int a[][5],int m,int n,int key){
    int i = 0,j=n-1;
    while (i<n && j>=0)
    {
        if(a[i][j]==key){
            cout<<"Found at cell"<<" "<<i+1<<" "<<j+1;
            return true;
        }
        else if(a[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"Key not found";
    return false;
    
}

int main()
{
    int arr[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int key = 10;
    bruteForce(arr, 5, 5, 10);
    cout<<"\nFrom step approach"<<endl;
    step(arr,5,5,10);
}