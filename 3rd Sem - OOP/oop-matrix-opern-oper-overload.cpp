#include <iostream>
using namespace std;

class Matrix
{
public:
  int row;
  int col;
  int matrix[10][10];

  Matrix(int m[10][10], int r, int c)
  {
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        matrix[i][j] = m[i][j];
      }
    }

    row = r;
    col = c;
  }

  Matrix operator+(Matrix &obj)
  {
    int sum_mat[10][10];
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        sum_mat[i][j] = matrix[i][j] + obj.matrix[i][j];
      }
    }
    return Matrix(sum_mat, row, col);
  }

  Matrix operator-(Matrix &obj)
  {
    int sub_mat[10][10];
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        sub_mat[i][j] = matrix[i][j] - obj.matrix[i][j];
      }
    }
    return Matrix(sub_mat, row, col);
  }

  Matrix operator*(Matrix &obj)
  {
    int mul_mat[10][10];
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < obj.col; j++)
      {
        mul_mat[i][j] = 0;
        for (int k = 0; k < col; k++)
        {
          mul_mat[i][j] += matrix[i][k] * obj.matrix[k][j];
        }
      }
    }
    return Matrix(mul_mat, row, obj.col);
  }

  Matrix operator~()
  {
    int trans_mat[10][10];
    for (int j = 0; j < col; j++)
    {
      for (int i = 0; i < row; i++)
      {
        trans_mat[j][i] = matrix[i][j];
      }
    }
    return Matrix(trans_mat, col, row);
  }

  void display()
  {
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        cout << " " << matrix[i][j];
      }
      cout << endl;
    }
  }
};

int main()
{
  int r1, c1;
  int r2, c2;

  cout << "Enter Size of 1st Matrix : ";
  cin >> r1 >> c1;

  int mat_1[10][10];
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c1; j++)
    {
      cout << "1st Matrix " << "[" << i << "]" << "[" << j << "] : ";
      cin >> mat_1[i][j];
    }
  }
  cout << endl;

  cout << "Enter Size of 2nd Matrix : ";
  cin >> r2 >> c2;

  int mat_2[10][10];
  for (int i = 0; i < r2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cout << "2nd Matrix " << "[" << i << "]" << "[" << j << "] : ";
      cin >> mat_2[i][j];
    }
  }
  cout << endl;

  cout << "1st Matrix" << endl;
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c1; j++)
    {
      cout << " " << mat_1[i][j];
    }
    cout << endl;
  }

  cout << "2nd Matrix" << endl;
  for (int i = 0; i < r2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cout << " " << mat_2[i][j];
    }
    cout << endl;
  }

  Matrix m1(mat_1, r1, c1);
  Matrix m2(mat_2, r2, c2);

  if (r1 != r2 || c1 != c2)
  {
    cout << "Addition & Subtraction not possible !" << endl;
  }
  else
  {
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 - m2;

    cout << endl
         << "Addition : " << endl;
    m3.display();

    cout << endl
         << "Subtraction : " << endl;
    m4.display();
  }

  if (c1 != r2)
  {
    cout << " Multiplication not possible !" << endl;
  }
  else
  {
    Matrix m5 = m1 * m2;
    cout << endl
         << "Multiplication : " << endl;
    m5.display();
  }

  Matrix m6 = ~m1;
  Matrix m7 = ~m2;

  cout << endl
       << "Transpose of 1st Matrix : " << endl;
  m6.display();

  cout << endl
       << "Transpose of 2nd Matrix : " << endl;
  m7.display();

  return 0;
}