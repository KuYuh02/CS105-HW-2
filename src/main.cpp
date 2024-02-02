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

bool isPrime(int n) {
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

std::vector<int> findPrimeFactors(int n) {
    std::vector<int> primeFactors;
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

// int decrypt(int c, int d, int n) {
//     int answer = 1;
//     c = c % n;
//     while (d > 0) {
//         if (d % 2 == 1) {
//             answer = (answer*c) % n;
//         }
//         c = (c * c) % n;
//         d /= 2;
//     }
//     return answer;
// }

int main()
{   

    // int e = 7;
    // int n = 4453;
    // int p = 61;
    // int q = 73; 
    // int phiN = 4320;
    // int d = 3703;
    // int m = 0;
    int e, n, m, p, q, phiN, d;
    int c;
    long long decrypted;
    

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
    vector<int> factorsN = findPrimeFactors(n);
    p = factorsN[0];
    q = factorsN[1];
    phiN =  (p-1)*(q-1);
    d = modInverse(e, phiN);
    cout << "p: " << p << " and q: " << q << endl;
    cout << "phi(n): " << phiN << endl;
    cout << "d: " << d << endl;

    // decrypted = (c, d, n);
    // cout << "Decrypted int: " << decrypted << endl;
    

    return 0;
}
