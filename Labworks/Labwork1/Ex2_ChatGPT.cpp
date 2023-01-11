#include <iostream>
#include <cstdlib>
#include <cstdint>

// Function to perform the square-and-multiply algorithm
uint64_t squareAndMultiply(uint64_t x, uint64_t e, uint64_t m)
{
    // Initialize result to 1
    uint64_t result = 1;

    // While there are bits in the exponent
    while (e > 0)
    {
        // If the current bit is 1, multiply the result by x modulo m
        if (e & 1) result = (result * x) % m;

        // Square x modulo m
        x = (x * x) % m;

        // Shift the exponent to the right by 1 bit
        e >>= 1;
    }

    return result;
}

int main()
{
    // Test the function with some example inputs
    std::cout << squareAndMultiply(2, 10, 1000) << std::endl;
    std::cout << squareAndMultiply(5, 20, 10000) << std::endl;
    std::cout << squareAndMultiply(3, 30, 100000) << std::endl;

    return 0;
}
