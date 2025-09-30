#include <iostream>
using namespace std;

void diagonalSum(int arr[][5], int m, int n)//time complexity is o(n^2)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
            if (j == n - i - 1)
            {
                sum += arr[i][j];
            }
        }
    }
    cout << "\nSUM IS " << sum;
}

void dsumEff(int arr[][5],int m,int n){
    int sum =0;
    for (int i = 0; i < m; i++)
    {
        sum+=arr[i][i];
        sum+=arr[i][n-i-1];
    }
    cout<<"\nEfficient algo O(n) "<<sum;
}

void pDiagonalPrint(int arr[][5], int m, int n)
{
    int pdSum = 0;
    for (int i = 0; i < m; i++)
    {
        cout << arr[i][i] << " ";
        pdSum += arr[i][i];
    }
    cout << "\nSum of Primay diagonal elements  : " << pdSum;
}
void sDiagonalPrint(int arr[][5], int m, int n)
{
    int sdSum = 0;
    for (int i = 0; i < m; i++)
    {
        cout << arr[i][n - i - 1] << " ";
        sdSum += arr[i][n - i - 1];
    }
    cout << "\nSecondary diagonal sum is : " << sdSum;
}
int main()
{
    int arr[5][5] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (i * j) + (i * j);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Printing primary diagonal\n";
    pDiagonalPrint(arr, 5, 5);
    cout << "\nPrinting secondary diagonal\n";
    sDiagonalPrint(arr, 5, 5);
    diagonalSum(arr, 5, 5);
    dsumEff(arr,5,5);
}
