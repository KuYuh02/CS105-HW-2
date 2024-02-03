#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


long gcd(long a, long b) {
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool is_valid(long e, long n){
    if(e < 2 || e >= n){
        return false;
    }

    if(gcd(e,n) != 1) {
        return false;
    }
    return true;
}

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<long long> findPrimeFactors(long long n) {
    std::vector<long long> primeFactors;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0 && isPrime(i) && isPrime(n/i) && i != (n/i)) { //make sure both factors are prime and are not equal to each other
            primeFactors.push_back(i);  
            primeFactors.push_back(n/i);                                       //get second prime number by diving first by n
            break;                                                                 // We only need two prime factors
        }
    }

    return primeFactors;
}

long long modInverse(long long e, long long phiN) {
    long long d = 0;
    while ((e * d) % phiN != 1) { //continue incrementing d until the product is congruent to 1 mod phi of n
        d++;
    }
    return d;
}

long long modularMultiplication(long long c, long long d, long long n) {
    long long result = 0;
    c %= n;
    while (d > 0) {
        if (d & 1) {        //check if d is odd, if so take it out and use recurrence
            result = (result + c) % n;
        }
        c = (2 * c) % n;
        d >>= 1;        //shift is equivalent to dividing by two, more efficient for big numbers
    }
    return result;
}

long long decrypt(long long c, long long d, long long n) {           //Use recurrence recursively to make sure number doesnt get too big for large exponents
    // Base cases
    if (d == 0)
        return 1;
    if (d == 1)
        return c % n;
    
    long long halfPower = decrypt(c, d >> 1, n);                         //divide d by two to get 'half power' and square d instead
    long long halfPowerSquared = modularMultiplication(halfPower, halfPower, n);
    
    // If the exponent is odd
    if (d & 1) {
        return modularMultiplication(halfPowerSquared, c, n);
    }
    
    return halfPowerSquared;
}

int main()
{   
    long long e, n, m, p, q, phiN, d, c;
    

    //Part (i)
    cout << "Enter e: " << endl;
    cin >> e;
    cout << "Enter n: " << endl;
    cin >> n;
    //Part (ii)
    if(is_valid(e,n)){
        cout << "The public key you have entered is VALID!" << endl;
    }
    else{
        cout << "INVALID PUBLIC KEY!!!" << endl;
        return 0;                               //quit if invalid
    }
    
    cout << "Enter m (the number of characters in the message): " << endl;
    cin >> m;
    cout << "Enter cyphertext (c): ";
    cin >> c;

    //Part (vi)
    vector<long long> factorsN = findPrimeFactors(n);
    p = factorsN[0];
    q = factorsN[1];
    phiN =  (p-1)*(q-1);
    d = modInverse(e, phiN);
    cout << "p: " << p << " and q: " << q << endl;
    cout << "phi(n): " << phiN << endl;
    cout << "d: " << d << endl;

    long long decrypted = decrypt(c, d, n);

    cout << "Decrypted int: " << decrypted << endl;
    

    return 0;
}
