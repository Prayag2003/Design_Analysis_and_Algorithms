#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (int row = 0; row <= matrix.size() - 1; row++)
    {
        for (int col = 0; col <= matrix[0].size() - 1; col++)
        {
            cout << "   " << matrix[row][col] << "    ";
        }
        cout << "\n";
    }
    return;
}

void addMatrix(vector<vector<int>> first, vector<vector<int>> second, vector<vector<int>> &product, int index)
{
    for (int row = 0; row < index; row++)
    {
        for (int col = 0; col < index; col++)
        {
            product[row][col] = first[row][col] + second[row][col];
        }
    }
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> first, vector<vector<int>> second)
{
    int col1 = first[0].size(), row1 = first.size();
    int col2 = second[0].size(), row2 = second.size();

    vector<int> rowProduct(col2, 0);
    vector<vector<int>> product(row1, rowProduct);

    if (col1 == 1)
        product[0][0] = first[0][0] * second[0][0];
    else
    {
        int index = col1 / 2;

        vector<int> row(index, 0);
        vector<vector<int>> product_00(index, row);
        vector<vector<int>> product_01(index, row);
        vector<vector<int>> product_10(index, row);
        vector<vector<int>> product_11(index, row);

        vector<vector<int>> a00(index, row);
        vector<vector<int>> a01(index, row);
        vector<vector<int>> a10(index, row);
        vector<vector<int>> a11(index, row);
        vector<vector<int>> b00(index, row);
        vector<vector<int>> b01(index, row);
        vector<vector<int>> b10(index, row);
        vector<vector<int>> b11(index, row);

        for (int row = 0; row < index; row++)
            for (int col = 0; col < index; col++)
            {
                a00[row][col] = first[row][col];
                a01[row][col] = first[row][col + index];
                a10[row][col] = first[index + row][col];
                a11[row][col] = first[row + index][col + index];
                b00[row][col] = second[row][col];
                b01[row][col] = second[row][col + index];
                b10[row][col] = second[index + row][col];
                b11[row][col] = second[row + index][col + index];
            }

        addMatrix(multiplyMatrix(a00, b00), multiplyMatrix(a01, b10), product_00, index);
        addMatrix(multiplyMatrix(a00, b01), multiplyMatrix(a01, b11), product_01, index);
        addMatrix(multiplyMatrix(a10, b00), multiplyMatrix(a11, b10), product_10, index);
        addMatrix(multiplyMatrix(a10, b01), multiplyMatrix(a11, b11), product_11, index);

        for (int row = 0; row < index; row++)
            for (int col = 0; col < index; col++)
            {
                product[row][col] = product_00[row][col];
                product[row][col + index] = product_01[row][col];
                product[index + row][col] = product_10[row][col];
                product[row + index][col + index] = product_11[row][col];
            }
    }
    return product;
}

int main()
{
    cout << " \n\n ------------------------- Stresson's Multiplcation -------------------------   \n";

    vector<vector<int>> first = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    cout << " ------------------------------- First Matrix ------------------------------- \n";
    printMatrix(first);
    cout << "\n";

    vector<vector<int>> second = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    cout << " ------------------------------ Second Matrix ------------------------------- \n";
    printMatrix(second);
    cout << "\n";

    vector<vector<int>> product(multiplyMatrix(first, second));
    cout << " ------------------------------ Product Matrix ------------------------------\n";
    printMatrix(product);
    cout << "\n";
}
