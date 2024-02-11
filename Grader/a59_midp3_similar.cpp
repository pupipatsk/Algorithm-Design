#include <iostream>

using namespace std;

bool similar(string a, string b) {
    int n = a.size();

    // terminate condition
    if (n == 1) return a == b;

    // condition 1
    if (a == b) return true;

    // condition 2
    string a1 = a.substr(0,n/2);
    string a2 = a.substr(n/2,n/2);
    string b1 = b.substr(0,n/2);
    string b2 = b.substr(n/2,n/2);

    bool cond2_1 = similar(a1, b1) && similar(a2, b2);
    bool cond2_2 = similar(a1, b2) && similar(a2, b1);
    bool cond2 = cond2_1 || cond2_2;
    return cond2;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (similar(a,b)) cout << "YES";
    else cout << "NO";

    return 0;
}