/*
* @Author: nevil
* @Date:   2020-07-24 16:03:04
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-24 16:08:26
*/
#include<bits/stdc++.h>
using namespace std;

void swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

long long gcd(long long a, long long m) {
    if (a > m) swap(a, m);
    long long r;
    for (;;) {
        r = m % a;
        if (r == 0) return a;
        m = a;
        a = r;
    };
}

long long power(long long a, long long b, long long m) {
    if (a > m) swap(a, m);
    long long c = 1;
    for (;;) {
        if (b % 2 == 1) c = (c * a) % m;
        b = b / 2;
        if (b == 0) return c;
        a = (a * a) % m;
    };
}

bool fermat(long long m) {
    srand(time(NULL));
    if (m == 1) {
        cout << endl;
        return false;
    };
    for (int i = 0; i < 1000; i++) {
        int cnt = i + 1;
        long long a = rand() % m;
        if (a == 0) a = 1;
        if (gcd(a, m) != 1) {
            cout << "\nFailed at the " << "attempt " << cnt << endl;
            cout << "Found a divisor: " << gcd(a, m) << ", thus ";
            return false;
        };
        if (power(a, m - 1, m) != 1) {
            cout << "\nFailed at the " << cnt << ". attempt. ";
            cout << "Found a Fermat witness: " << a << ", thus ";
            return false;
        };
    };
    cout << endl;
    return true;
}

int main() {

    cout << "Fermat primality test" << endl << endl;
    for (;;) {
        long long n;
        cout << "Please input a natural number (0 to quit): ";
        cin >> n;
        if (n == 0) return 0;
        bool b = fermat(n);
        if (b) cout << n << " is probably a prime." << endl << endl;
        if (!b) cout << n << " is not a prime." << endl << endl;
    };
}
