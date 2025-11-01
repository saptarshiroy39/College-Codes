#include<iostream>
using namespace std;

void crc(int data[], int divisor[], int len, int divlen) {
    for(int i = 0; i < len; i++)
        if(data[i] == 1)
            for(int j = 0; j < divlen; j++)
                data[i+j] ^= divisor[j];
}

int main() {
    int data[20], divisor[10], len, divlen;

    cout << "\nEnter divisor length: ";
    cin >> divlen;
    cout << "Enter divisor: ";
    for(int i = 0; i < divlen; i++) cin >> divisor[i];

    cout << "\nEnter data length: ";
    cin >> len;
    cout << "Enter data: ";
    for(int i = 0; i < len; i++) cin >> data[i];
    for(int i = len; i < len + divlen - 1; i++) data[i] = 0;

    cout << "\nData + zeros: ";
    for(int i = 0; i < len + divlen - 1; i++) cout << data[i];

    crc(data, divisor, len, divlen);
    cout << "\n\nCRC: ";
    for(int i = 1; i < divlen; i++) cout << data[i];

    cout << "\n\n--- RECEIVER ---\nEnter data + CRC: ";
    for(int i = 0; i < len + divlen - 1; i++) cin >> data[i];

    crc(data, divisor, len, divlen);
    int error = 0;
    cout << "\nCRC: ";
    for(int i = 1; i < divlen; i++) { cout << data[i]; error += data[i]; }

    cout << "\n" << (error ? "Error detected" : "No error") << "\n";
    return 0;
}