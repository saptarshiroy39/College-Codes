#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

using Complex = complex<double>;

void FFT(Complex A[], int N)
{
  if (N <= 1)
    return;

  Complex X[N / 2], Y[N / 2];
  for (int i = 0; i < N / 2; i++)
  {
    X[i] = A[i * 2];
    Y[i] = A[i * 2 + 1];
  }

  FFT(X, N / 2);
  FFT(Y, N / 2);

  Complex W = exp(Complex(0, 2 * M_PI / N)), P = 1;
  for (int r = 0; r < N / 2; r++)
  {
    Complex term = P * Y[r];
    A[r] = X[r] + term;
    A[r + N / 2] = X[r] - term;
    P *= W;
  }
}

int main()
{
  int N;
  cout << "Enter number of elements (must be 2^x): ";
  cin >> N;
  Complex A[N];

  cout << "Enter the elements: ";
  for (int i = 0; i < N; i++)
  {
    double realPart;
    cin >> realPart;
    A[i] = Complex(realPart, 0);
  }

  FFT(A, N);

  cout << "Transformed array (FFT result): " << endl;
  for (int i = 0; i < N; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}