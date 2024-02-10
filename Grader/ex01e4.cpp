#include <iostream>
#include <vector>

using namespace std;

int mod_expo(int x, int n, int k) {
    if (n == 1) return x % k;
    if (n%2 == 0) { // x^even // x^2n = x^n * x^n
        int tmp = mod_expo(x,n/2,k);
        return ( tmp * tmp ) % k;
    }
    else { // x^2n+1 = (x^n * x^n) * x //   ( (x^n * x^n mod k) x mod k ) mod k 
        int tmp = mod_expo(x,n/2,k); // x^n mod k
        tmp = (tmp * tmp) % k; // x^n * x^n mod k
        return ( tmp * (x % k) )% k;
    }
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;

    cout << mod_expo(x,n,k);
    
    return 0;
}