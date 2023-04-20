#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i <= matrix[0].size() - 1; i++)
    {
        for (int j = 0; j <= matrix.size() - 1; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

vector<vector<int>>add_matrix(vector<vector<int>>first,vector<vector<int>> second, int half_ind,int multiplyWith=1)
{
    for (int i = 0; i < half_ind; i++)
        for (int j = 0; j < half_ind; j++)
            first[i][j] = first[i][j] + (multiplyWith * second[i][j]);
    return first;
}

vector<vector<int>> multiply_matrix(vector<vector<int>> first, vector<vector<int>> second)
{
    int c1 = first[0].size();
    int r1 = first.size();
    int c2 = second[0].size();
    int r2 = second.size();

    if (c1 != r2)
    {
        cout << "\nNumber of Rows in A is not equal to Number of columns in B\n";
        return {};
    }

    vector<int> prod_matrix_row(c2, 0);
    vector<vector<int>> prod_matrix(r1,
                                    prod_matrix_row);

    if (c1 == 1)
        prod_matrix[0][0] = first[0][0] * second[0][0];
    else
    {
        int half_ind = c1 / 2;

        vector<int> row_vector(half_ind, 0);

        vector<vector<int>> a00(half_ind, row_vector);
        vector<vector<int>> a01(half_ind, row_vector);
        vector<vector<int>> a10(half_ind, row_vector);
        vector<vector<int>> a11(half_ind, row_vector);
        vector<vector<int>> b00(half_ind, row_vector);
        vector<vector<int>> b01(half_ind, row_vector);
        vector<vector<int>> b10(half_ind, row_vector);
        vector<vector<int>> b11(half_ind, row_vector);

        for (int i = 0; i < half_ind; i++)
            for (int j = 0; j < half_ind; j++)
            {
                a00[i][j] = first[i][j];
                a01[i][j] = first[i][j + half_ind];
                a10[i][j] = first[half_ind + i][j];
                a11[i][j] = first[i + half_ind]
                                 [j + half_ind];
                b00[i][j] = second[i][j];
                b01[i][j] = second[i][j + half_ind];
                b10[i][j] = second[half_ind + i][j];
                b11[i][j] = second[i + half_ind]
                                  [j + half_ind];
            }

        vector<vector<int>> p(multiply_matrix(
            a00, add_matrix(b01, b11, half_ind, -1)));
        vector<vector<int>> q(multiply_matrix(
            add_matrix(a00, a01, half_ind), b11));
        vector<vector<int>> r(multiply_matrix(
            add_matrix(a10, a11, half_ind), b00));
        vector<vector<int>> s(multiply_matrix(
            a11, add_matrix(b10, b00, half_ind, -1)));
        vector<vector<int>> t(multiply_matrix(
            add_matrix(a00, a11, half_ind),
            add_matrix(b00, b11, half_ind)));
        vector<vector<int>> u(multiply_matrix(
            add_matrix(a01, a11, half_ind, -1),
            add_matrix(b10, b11, half_ind)));
        vector<vector<int>> v(multiply_matrix(
            add_matrix(a00, a10, half_ind, -1),
            add_matrix(b00, b01, half_ind)));

        vector<vector<int>> prod_matrix_00(add_matrix(
            add_matrix(add_matrix(t, s, half_ind), u,
                       half_ind),
            q, half_ind, -1));
        vector<vector<int>> prod_matrix_01(
            add_matrix(p, q, half_ind));
        vector<vector<int>> prod_matrix_10(
            add_matrix(r, s, half_ind));
        vector<vector<int>> prod_matrix_11(add_matrix(
            add_matrix(add_matrix(t, p, half_ind), r,
                       half_ind, -1),
            v, half_ind, -1));

        for (int i = 0; i < half_ind; i++)
            for (int j = 0; j < half_ind; j++)
            {
                prod_matrix[i][j] = prod_matrix_00[i][j];
                prod_matrix[i][j + half_ind] = prod_matrix_01[i][j];
                prod_matrix[half_ind + i][j] = prod_matrix_10[i][j];
                prod_matrix[i + half_ind]
                           [j + half_ind] = prod_matrix_11[i][j];
            }

        a00.clear();a01.clear();a10.clear();a11.clear();
        b00.clear();b01.clear();b10.clear();b11.clear();

        p.clear();q.clear();r.clear();s.clear();
        t.clear();u.clear();v.clear();

        prod_matrix_00.clear();prod_matrix_01.clear();
        prod_matrix_10.clear();prod_matrix_11.clear();
    }
    return prod_matrix;
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

    vector<vector<int>> prod_matrix(
        multiply_matrix(first, second));
    cout << " ------------------------------ Product Matrix ------------------------------\n";
    printMatrix(prod_matrix);
    cout << "\n";
}
