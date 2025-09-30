#include <iostream>
using namespace std;
// need 4 variables
void spiralMatrix(int matrix[][5], int n, int m)
{
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;
    while (srow <= erow && scol<=ecol)//<= bcoz when we have odd rows or cols we encounter no problem
    {//at middle row srow = erow to print 
        //if we have odd cols then to print middle elements ecol=scol

        // top
        for (int j =scol    ; j <= ecol; j++)
        {
            cout << matrix[srow][j] << " ";
        }
        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << matrix[i][ecol] << " ";
        }
        // bottom
        for (int j = ecol - 1; j >= scol; j--)
        {   
            if (srow==erow)///when rows or odd without this one element duplicates
            {
                break;
            }
            
            cout << matrix[erow][j] << " ";
        }
        // left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
             if (scol==ecol)///when rows or odd without this one element duplicates
            {
                break;
            }
            cout << matrix[i][scol] << " ";
        }
        srow++, scol++;
        erow--, ecol--;
    }
}
int main()
{
    int arr[5][5] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (i * j) + (i + j);
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
    // int i = 0;
    // for (int j = 0; j < 5; j++)
    // {
    //     cout << arr[i][j] << " ";
    // }

    // int j = 4;
    // for (int i = 1; i < 5; i++)
    // {
    //     cout << arr[i][j] << " ";
    // }
    // i = 4;
    // for (int j = 3; j >= 0; j--)
    // {
    //     cout << arr[i][j] << " ";
    // }
    cout<<"Printing spirally\n";
    spiralMatrix(arr, 5, 5);

    return 0;
}
