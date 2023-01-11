#include <iostream>
#include <cmath>

using namespace std;

int p, q, e, d, M, C;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter q: ";
    cin >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    cout << "Enter e: ";
    cin >> e;

    // Ensure that e is relatively prime to phi
    while (gcd(e, phi) != 1)
    {
        cout << "e must be relatively prime to phi. Enter a different value for e: ";
        cin >> e;
    }

    // Compute d such that d * e = 1 (mod phi)
    int k = 1;
    while ((k * phi + 1) % e != 0)
    {
        k++;
    }

    d = (k * phi + 1) / e;

    cout << "Enter the message (M): ";
    cin >> M;

    // Encrypt the message
    C = fmod(pow(M, e), n);
    cout << "Ciphertext (C): " << C << endl;

    // Decrypt the message
    M = fmod(pow(C, d), n);
    cout << "Decrypted message (M): " << M << endl;

    return 0;
}