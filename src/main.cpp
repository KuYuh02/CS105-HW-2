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

vector<long long> findPrimeFactors(long long n) {
    vector<long long> primeFactors;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0 && isPrime(i) && isPrime(n/i) && i != (n/i)) {           //make sure both factors are prime and are not equal to each other
            primeFactors.push_back(i);  
            primeFactors.push_back(n/i);                                       //get second prime number by diving first by n
            break;                                                             // We only need two prime factors
        }
    }
    return primeFactors;
}

long long modInverse(long long e, long long phiN) {
    long long d = 0;
    while ((e * d) % phiN != 1) {                                               //continue incrementing d until the product is congruent to 1 mod phi of n
        d++;
    }
    return d;
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

long long decrypt(long long c, long long d, long long n) {           //Use recurrence recursively to make sure number doesnt get too big for large exponents
    if (d == 0)
        return 1;
    if (d == 1)
        return c % n;
    long long halfPower = decrypt(c, d >> 1, n);                         //divide d by two to get 'half power' and square d instead
    long long halfPowerSquared = modularMultiplication(halfPower, halfPower, n);
    if (d & 1) {                                                        //if exponent is odd, take it out to be even and run even algorithm
        return modularMultiplication(halfPowerSquared, c, n);
    }
    return halfPowerSquared;
}

int main()
{   
    long long e, n, m, p, q, phiN, d, c;
    string cipherText;
    vector<long long> cipherNumbers;
    

    //Part (i)
    cout << "Enter e: " << endl;
    cin >> e;
    cout << "Enter n: " << endl;
    cin >> n;
    if (isPrime(n)) {
        cout << "n should not be a prime number in RSA. Please enter a composite number that is the product of two primes." << endl;
        return 0;
    }



    cout << "Enter m (the number of characters in the message): " << endl;
    cin >> m;
    cin.ignore();
    cout << "Enter ciphertext (c): ";
    getline(cin, cipherText);

    //Part (ii)
    if(!is_valid(e,n)){
       cout << "Public key is not valid!" << endl;
        return 0;                                                               //quit if invalid
    }

    //get ciphertext and convert the string input into integer for the decrypt algorithm to decrypt
    string token;
    for (char c : cipherText) {
        if (isdigit(c)) {
            token += c;
        } else if (!token.empty()) {
            cipherNumbers.push_back(stoi(token));
            token.clear();
        }
    }
    if (!token.empty()) {
        cipherNumbers.push_back(stoi(token));
    }

    //Part (vi)
    vector<long long> factorsN = findPrimeFactors(n);
    p = factorsN[0];
    q = factorsN[1];
    phiN =  (p-1)*(q-1);
    d = modInverse(e, phiN);
    cout  << p << " " << q << " " << phiN << " " << d << " " << endl;
    long long decrypted; 


    cout << "Decrypted message as numbers " << endl;
    for (long long cipherNumber : cipherNumbers){
        decrypted = decrypt(cipherNumber, d, n);
        cout << decrypted << " ";
    }
    cout << endl;

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
    cout << endl;
    return 0;
}
