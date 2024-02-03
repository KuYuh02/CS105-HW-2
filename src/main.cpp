#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>
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
bool isPrime(long long n) {
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

int decrypt(int c, int d, int n) {
    int answer = 1; // This will hold the final answer
    int base = c % n; // The 'base' starts as c modulo n

    // The loop performs modular exponentiation by squaring
    while (d > 0) {
        if (d % 2 == 1) { // If the current power is odd
            answer = (answer * base) % n; // Multiply the current answer by the base
        }
        base = (base * base) % n; // Square the base
        d /= 2; // Divide the power by 2
    }
    return answer;
>>>>>>> 27d73c5 (Update main)
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

    //Part (ii)
    if(is_valid(e,n)){
        cout << "The public key you have entered is VALID!" << endl;
    }
    else if(!is_valid(e,n)){
        cout << "INVALID PUBLIC KEY!!!" << endl;
        return 0;                               //quit if invalid
    }
    
    cout << "Enter m (the number of characters in the message): " << endl;
    cin >> m;
    cout << "Enter cyphertext (c): ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, cipherText);


    stringstream ss(cipherText);
    int temp;
    while (ss >> temp) {
        cipherNumbers.push_back(temp);
    }


    //Part (vi)
    vector<long long> factorsN = findPrimeFactors(n);
    p = factorsN[0];
    q = factorsN[1];
    phiN =  (p-1)*(q-1);
    d = modInverse(e, phiN);
    cout << "p: " << p << " and q: " << q << endl;
    cout << "phi(n): " << phiN << endl;
    cout << "d: " << d << endl;

    
    
    decrypted = decrypt(c, d, n);
    
    cout << "Cipher numbers: ";
    for (const int& num : cipherNumbers) {
        cout << num << " ";
    }
    cout << endl;

    for (int cipherNumber : cipherNumbers){
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
        

    return 0;
}
