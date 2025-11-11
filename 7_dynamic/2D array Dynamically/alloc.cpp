#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter number of columns : ";
    cin >> cols;
    cout << "\n Enter number of rows: ";
    cin >> rows;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    int x = 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << matrix[2][2] << endl;
    cout << *(*(matrix + 2) + 2);
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}