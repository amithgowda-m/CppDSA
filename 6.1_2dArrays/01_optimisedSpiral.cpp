#include <iostream>
using namespace std;

// Function to print a matrix in spiral order
void spiralMatrix(int matrix[][5], int n, int m)
{
    // Start row & column
    int srow = 0, scol = 0;

    // End row & column
    int erow = n - 1, ecol = m - 1;

    // Loop until we’ve printed all layers
    // A “layer” means one complete rectangular ring around the matrix
    while (srow <= erow && scol <= ecol)
    {
        // -------------------------------
        // 1️ Print the TOP row
        // Move from left to right on the topmost unprinted row
        // Row index is fixed = srow
        for (int j = scol; j <= ecol; j++)
        {
            cout << matrix[srow][j] << " ";
        }

        // -------------------------------
        // 2️ Print the RIGHT column
        // Move from top to bottom on the rightmost unprinted column
        // Column index is fixed = ecol
        // Start from srow + 1 to avoid reprinting the corner element
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << matrix[i][ecol] << " ";
        }

        // -------------------------------
        // 3️ Print the BOTTOM row
        // Move from right to left on the bottommost unprinted row
        // But only if there is still a separate bottom row to print
        // (i.e. when srow < erow)
        if (srow < erow)
        {
            for (int j = ecol - 1; j >= scol; j--)
            {
                cout << matrix[erow][j] << " ";
            }
        }

        // -------------------------------
        // 4️ Print the LEFT column
        // Move from bottom to top on the leftmost unprinted column
        // But only if there is still a separate left column to print
        // (i.e. when scol < ecol)
        if (scol < ecol)
        {
            for (int i = erow - 1; i > srow; i--)
            {
                cout << matrix[i][scol] << " ";
            }
        }

        // -------------------------------
        // Move to the next inner layer
        // Shrink the boundaries
        srow++;
        scol++;
        erow--;
        ecol--;
    }
}

int main()
{
    // Create a 5x5 matrix
    int arr[5][5];

    // Fill the matrix with some values
    // Using a simple formula: arr[i][j] = (i * j) + (i + j)
    // This just generates distinct values for demonstration
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (i * j) + (i + j);
        }
    }

    // Print the matrix normally (row by row)
    cout << "Matrix:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // Print in spiral order
    cout << "\nPrinting in Spiral Order:\n";
    spiralMatrix(arr, 5, 5);

    return 0;
}
