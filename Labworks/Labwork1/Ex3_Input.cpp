#include <iostream>
#include <math.h>

using namespace std;

long long int p, q, n, phi, e, d, M, C;

long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long int power(long long int base, long long int exponent, long long int mod) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) result = (result * base) % mod;
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Test case 1
    p = 5;
    q = 11;
    e = 3;
    M = 9;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Key pair generation
    cout << "Key pair generation:" << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    cout << "phi: " << phi << endl;
    cout << "e: " << e << endl;

    // Encryption
    cout << "\nEncryption:" << endl;
    cout << "M: " << M << endl;
    C = power(M, e, n);
    cout << "C: " << C << endl;

    // Decryption
    cout << "\nDecryption:" << endl;
    cout << "C: " << C << endl;
    M = power(C, d, n);
    cout << "M: " << M << endl;

    // Test case 2
    p = 3;
    q = 11;
    d = 7;
    M = 5;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Key pair generation
    cout << "\nKey pair generation:" << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    cout << "phi: " << phi << endl;
    cout << "d: " << d << endl;

    // Decryption
    cout << "\nDecryption:" << endl;
    cout << "M: " << M << endl;
    C = power(M, d, n);
    cout << "C: " << C << endl;

    // Encryption
    cout << "\nEncryption:" << endl;
    cout << "C: " << C << endl;
    M = power(C, e, n);
    cout << "M: " << M << endl;

    return 0;
}