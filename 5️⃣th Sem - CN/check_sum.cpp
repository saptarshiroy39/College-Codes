#include <iostream>
using namespace std;

void add(int res[], int a[], int b[], int n, int c[] = nullptr) {
  int carry = 0;
  for (int i = 0; i < n; i++) {
    int temp = a[i] + b[i] + (c ? c[i] : 0) + carry;
    res[i] = temp % 2;
    carry = temp / 2;
  }
  while (carry) {
    int temp = res[0] + carry;
    res[0] = temp % 2;
    carry = temp / 2;
    for (int i = 1; i < n && carry; i++) {
      temp = res[i] + carry;
      res[i] = temp % 2;
      carry = temp / 2;
    }
  }
}

int main() {
  int a[10], b[10], c[10], sum[10], n;

  cout << "Enter number of bits: ";
  cin >> n;

  cout << "\n--- SENDER ---\n";

  cout << "Enter segment 1: ";
  for (int i = n - 1; i >= 0; i--) cin >> a[i];
  cout << "Enter segment 2: ";
  for (int i = n - 1; i >= 0; i--) cin >> b[i];

  add(sum, a, b, n);
  cout << "Sum:";
  for (int i = n - 1; i >= 0; i--) cout << " " << sum[i];
  cout << "\nChecksum:";
  for (int i = n - 1; i >= 0; i--) cout << " " << (1 - sum[i]);

  cout << "\n\n--- RECEIVER ---\n:";

  cout << "Enter segment 1: ";
  for (int i = n - 1; i >= 0; i--) cin >> a[i];
  cout << "Enter segment 2: ";
  for (int i = n - 1; i >= 0; i--) cin >> b[i];

  cout << "Enter checksum: ";
  for (int i = n - 1; i >= 0; i--) cin >> c[i];
  add(sum, a, b, n, c);
  cout << "Wrapped Sum:";
  for (int i = n - 1; i >= 0; i--) cout << " " << sum[i];
  cout << "\nChecksum:";
  for (int i = n - 1; i >= 0; i--) cout << " " << (1 - sum[i]);

  int allOnes = 1;
  for (int i = 0; i < n; i++) if (sum[i] != 1) allOnes = 0;

  cout << "\n" << (allOnes ? "Checksum PASSED." : "Checksum FAILED. Data Corrupted.") << "\n";
  return 0;
}