#include <iostream>
#include <string>
#include <algorithm>

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



int main()
{   

    // int e = 7;
    // int n = 4453;
    // int p = 61;
    // int q = 73; 
    // int phiN = 4320;
    // int d = 3703;
    // int m = 0;
    int e, n, m;
    string c = "";


    cout << "Enter e: " << endl;
    cin >> e;
    cout << "Enter n: " << endl;
    cin >> n;


    if(is_valid(e,n)){
        cout << "The public key you have entered is VALID!" << endl;
    }
    else{
        cout << "INVALID PUBLIC KEY!!!" << endl;
    }
    


    cout << "Enter m (the number of characters in the message): " << endl;
    cin >> m;

    cout << "Enter ciphertext (c): ";
    cin >> c;


    // cout << "p: " << p << endl;
    // cout << "q: " << q << endl;
    // cout << "φ(n): " << phiN << endl;
    // cout << "d: " << d << endl;
    

    return 0;
}
