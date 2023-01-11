#include <iostream>

// Define macros to use in the code
#define X_SIZE 19 // size of x register
# define Y_SIZE 22 // size of y register
# define Z_SIZE 23 // size of z register
# define BITS 10 // number of keystream bits

int majorBit(int x, int y, int z);

int main() {
    
  int maxB;
  int x0[X_SIZE] = {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
  int y0[Y_SIZE] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
  int z0[Z_SIZE] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};

  for (int i = 0; i < BITS; i++) {
    maxB = majorBit(x0[8], y0[10], z0[10]); // find the majority bit
    if (x0[8] == maxB) { //if maority bit matches with index bit in x register compute and shift
      // the register
      int p = x0[13] ^ x0[16] ^ x0[17] ^ x0[18]; // compute the polynomial for x register
      for (int j = X_SIZE - 1; j >= 0; j--) {
        if (j == 0) {
          x0[j] = p;
        } else {
          x0[j] = x0[j - 1];
        }
      }
    }

    if (y0[10] == maxB) { //if maority bit matches with index bit in y register compute and shift
      // the register
      int p = y0[20] ^ y0[21]; // compute the polynomial for y register
      for (int j = Y_SIZE - 1; j >= 0; j--) {
        if (j == 0) {
          y0[j] = p;
        } else {
          y0[j] = y0[j - 1];
        }
      }
    }

    if (z0[10] == maxB) { //if maority bit matches with index bit in y register compute and shift
      // the register
      int p = z0[7] ^ z0[20] ^ z0[21] ^ z0[22]; // compute the polynomial for z register
      for (int j = Z_SIZE - 1; j >= 0; j--) {
        if (j == 0) {
          z0[j] = p;
        } else {
          z0[j] = z0[j - 1];
        }
      }
    }
    if (i < BITS) {
      // print the keystream bit
      printf("\nKeystream Bit = %d", x0[X_SIZE - 1] ^ y0[Y_SIZE - 1] ^ z0[Z_SIZE - 1]);
      printf("\n");
    }
  }

  //print the register values after computing the A5/1 key
  printf("\nX: ");
  for (int j = 0; j < X_SIZE; j++) {
    printf("%d", x0[j]);
  }
  printf("\nY: ");
  for (int j = 0; j < Y_SIZE; j++) {
    printf("%d", y0[j]);
  }
  printf("\nZ: ");
  for (int j = 0; j < Z_SIZE; j++) {
    printf("%d", z0[j]);
  }

}

//function to determine majority bit
int majorBit(int x, int y, int z) {
  if (x == 0) {
    if (y == 0 || z == 0) {
      return 0; // x is already 0, now if either y or z is 0 majority bit is 0
    } else {
      return 1; // both y and z are 1, so majority bit is 1
    }
  } else {
    if (y == 1 || z == 1) {
      return 1; // x is already 1, now if either y or z is 1 majority bit is 1
    } else {
      return 0; // both y and z are 0, so majority bit is 0
    }
  }
}