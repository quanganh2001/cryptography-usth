#include <iostream>
using namespace std;

// Function to perfrom modular exponentation
int modular_pow(int base, int exponent, int modulus)
{
    // initialize result
    int result = 1;

    while (exponent > 0)
    {
        // if exponent is odd
        if (exponent & 1)
            result = (result * base) % modulus;
        
        // exponent = exponent / 2
        exponent = exponent >> 1;

        // base = base * base
        base = (base * base) % modulus;
    }

    return result;
}

int main()
{
    int base, exponent, modulus;

    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    cout << "Enter modulus: ";
    cin >> modulus;

    cout << "Result: " << modular_pow(base, exponent, modulus) << endl;

    return 0;
}