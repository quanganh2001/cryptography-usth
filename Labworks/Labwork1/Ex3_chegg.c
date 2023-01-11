#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n) {
    int i;
    int m = n / 2;
    
    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int findGCD(int n1, int n2) {
    int i, gcd;

    for(i = 1; i <= n1 && i <= n2; ++i) {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    return gcd;
}

int powMod(int a, int b, int n) {
    long long x = 1, y = a;

    while (b > 0) {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n;
        b /= 2;
    }

    return x % n;
}

int modInverse(int a, int m) 
{ 
    int x;
    a = a%m; 
    for (x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 

int main(int argc, char* argv[]) {
    int p, q, e, d;
    int n, phi;
    char ch;
    int num, cipher, decrypt;
    printf("Mention if e or d is given:");
    scanf("%c",&ch);
    while (1) {
        printf("Enter value for p,q:");
        scanf("%d %d", &p, &q);

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Both numbers are not prime. Please enter prime numbers only\n");
        else if (!checkPrime(p))
            printf("The first number you entered is not prime, please try again\n");
        else if (!checkPrime(q))
            printf("The second number you entered is not prime, please try again\n");
        else
            break;
    }
    
    n = p * q;

    phi = (p - 1) * (q - 1);
    

    if(ch=='d')
    {
        printf("Provide value for d:");
        scanf("%d",&d);
        e=modInverse(d,phi);
    }
    else
    {
        printf("Provide value for e:");
        scanf("%d",&e);
        d = 0;
        for (d = e + 1; d <= 100; d++) {
            if ( ((d * e) % phi) == 1)
                break;
        }
    }
    printf("Value of e: %d\nValue of d: %d\n", e, d);

    printf("Enter number to encrypt: ");
    scanf("%d", &num);

    cipher = powMod(num, e, n);
    printf("The cipher number is: %d\n", cipher);

    decrypt = powMod(cipher, d, n);
    printf("The decrypted number is: %d\n", decrypt);
    return 0;
}