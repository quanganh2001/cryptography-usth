#include <iostream>
#include <bitset>

using namespace std;

// Generate one keystream bit
int generateBit(bitset<19> &x, bitset<22> &y, bitset<23> &z) {
    int bit = (x[8] + y[10] + z[9]) % 2;

    // Shift registers
    x = ((x << 1).to_ulong() | bit) & 0x3fffff;
    y = ((y << 1).to_ulong() | bit) & 0x7fffff;
    z = ((z << 1).to_ulong() | bit) & 0x3ff;

    return bit;
}

int main() {
    // Initialize registers
    bitset<19> x(0b1111101010101010101);
    bitset<22> y(0b1100110011001100110011);
    bitset<23> z(0b11100001111000011110000);

    // Generate keystream
    for (int i = 0; i < 10; i++) {
        int bit = generateBit(x, y, z);
        cout << bit;
    }
    
    return 0;
}