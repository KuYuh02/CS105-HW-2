#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;


long gcd(long a, long b) {
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool is_valid(long e, long phiN){
    if(e < 2 || e >= phiN){
        return false;
    }

    if(gcd(e,phiN) != 1) {
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

vector<long long> findPrimeFactors(long long n) {
    vector<long long> primeFactors;
    if (n % 2 == 0) {
        primeFactors.push_back(2);
        primeFactors.push_back(n / 2);
        return primeFactors;
    }
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            primeFactors.push_back(i);
            primeFactors.push_back(n / i);
            return primeFactors;
        }
    }
    primeFactors.push_back(1);
    primeFactors.push_back(n);
    return primeFactors;
}

long long gcdExtended(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1; 
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

long long modInverse(long long e, long long phiN) {
    long long x, y;
    long long g = gcdExtended(e, phiN, &x, &y);
    if (g != 1) {
        return -1;
    } else {
        return (x % phiN + phiN) % phiN;
    }
}

long long modularMultiplication(long long c, long long d, long long n) {
    long long result = 0;
    c %= n;
    while (d > 0) {
        if (d & 1) {                                                        //check if d is odd, if so take it out and use recurrence
            result = (result + c) % n;
        }
        c = (2 * c) % n;
        d >>= 1;                                                            //shift is equivalent to dividing by two, more efficient for big numbers
    }
    return result;
}

long long decrypt(long long c, long long d, long long n) {
    if (d == 0)
        return 1;
    if (d == 1)
        return c % n;
    if (d % 2 == 0) {
        long long halfPower = decrypt(c, d / 2, n);
        return modularMultiplication(halfPower, halfPower, n);
    } else {
        long long halfPower = decrypt(c, d / 2, n);
        long long halfPowerSquared = modularMultiplication(halfPower, halfPower, n);
        return modularMultiplication(halfPowerSquared, c, n);
    }
}

int main()
{   
    long long e, n, m, p, q, phiN, d, c;
    string cipherText;
    vector<long long> cipherNumbers;
    

    //Part (i)
    //cout << "Enter e: " << endl;
    cin >> e >> n;
    //cout << "Enter n: " << endl;
    //cin >> n;


    //cout << "Enter m (the number of characters in the message): " << endl;
    cin >> m;\
    cin.ignore();
    //cout << "Enter ciphertext (c): ";
    getline(cin, cipherText);

   

    //get ciphertext and convert the string input into integer for the decrypt algorithm to decrypt
    string token;
    bool inToken = false;
    for (char c : cipherText) {
        if (isdigit(c)) {
            token += c;
            inToken = true;
        } 
        else if (inToken) {
            cipherNumbers.push_back(stoi(token));
            token.clear();
            inToken = false;
        }
    
    }
    if (inToken) {
        cipherNumbers.push_back(stoi(token));
    }

    //Part (vi)
    vector<long long> factorsN = findPrimeFactors(n);
    p = factorsN[0];
    q = factorsN[1];
    phiN =  (p-1)*(q-1);
    //Part (ii)
    if(!is_valid(e,phiN)){
        cout << "Public key is not valid!";
        return 0;                                                               //quit if invalid
    }
    d = modInverse(e, phiN);
    cout  << p << " " << q << " " << phiN << " " << d << "\n";
    long long decrypted; 

    for (long long cipherNumber : cipherNumbers){
        decrypted = decrypt(cipherNumber, d, n);
        cout << decrypted << " ";
    }

    cout << "\n";
    for (long long cipherNumber : cipherNumbers){
        decrypted = decrypt(cipherNumber, d, n);
        switch(decrypted){
        case(7): cout << 'A' ; break;
        case(8): cout << 'B' ; break;
        case(9): cout << 'C' ; break;
        case(10): cout << 'D' ; break;
        case(11): cout << 'E' ; break;
        case(12): cout << 'F' ; break;
        case(13): cout << 'G' ; break;
        case(14): cout << 'H' ; break;
        case(15): cout << 'I' ; break;
        case(16): cout << 'J' ; break;
        case(17): cout << 'K' ; break;
        case(18): cout << 'L' ; break;
        case(19): cout << 'M' ; break;
        case(20): cout << 'N' ; break;
        case(21): cout << 'O' ; break;
        case(22): cout << 'P' ; break;
        case(23): cout << 'Q' ; break;
        case(24): cout << 'R' ; break;
        case(25): cout << 'S' ; break;
        case(26): cout << 'T' ; break;
        case(27): cout << 'U' ; break;
        case(28): cout << 'V' ; break;
        case(29): cout << 'W' ; break;
        case(30): cout << 'X' ; break;
        case(31): cout << 'Y' ; break;
        case(32): cout << 'Z' ; break;
        case(33): cout << ' ' ; break;
        case(34): cout << '"' ; break;
        case(35): cout << ',' ; break;
        case(36): cout << '.' ; break;
        case(37): cout << "'"; break;
        }
    }
    //cout << "\n";
    return 0;
}