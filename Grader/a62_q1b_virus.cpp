#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool solve(vector<int> &v, int l, int r) {
    // Base Case: virus length 2 only "01"
    if (l+1 == r) { // length=2
        if (v[0]==0 && v[1]==1) return true;
        else return false;
    }

    int mid = (l+r) / 2;

    vector<int> a, a_rev;
    for (int i = l; i <= mid; i++) a.push_back(v[i]);
    for (int i = a.size()-1; i >= 0; i--) {
        a_rev.push_back(a[i]);
    }
    // Debugging: Print contents of vectors a and a_rev
    // cout << "Vector a: ";
    // for (auto &e : a) {
    //     cout << e << " ";
    // }
    // cout << endl;

    // cout << "Vector a_rev: ";
    // for (auto &e : a_rev) {
    //     cout << e << " ";
    // }
    // cout << endl;

    vector<int> b;
    for (int i = mid+1; i <= r; i++) b.push_back(v[i]);
    // Debugging: Print contents of vectors a and a_rev
    // cout << "Vector a: ";
    // for (auto &e : b) {
    //     cout << e << " ";
    // }
    // cout << endl;

    bool similar = false;
    if (b == a || b == a_rev) similar = true;
    
    return similar;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {

        vector<int> v(pow(2,k));
        for (int j = 0; j < pow(2,k); j++) cin >> v[j];
        
        if (solve(v,0,pow(2,k)-1)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

// ---------- still wrong, 10 points ----------

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// bool solve(vector<int> &v, int l, int r, bool swp) {
//     // Base Case: length 2: // 01 when swp==0 // 10, when swp==1
//     if (l+1 == r) { // if length == 2
//         if (!swp) return v[0] == 0 && v[1] == 1;
//         else return v[0] == 1 && v[1] == 0;
//     }

//     int mid = (l+r) / 2;

//     bool a = solve(v,l,mid,0);
//     bool a_rev = solve(v,l,mid,1);
//     bool b = solve(v,mid+1,r,0);
//     bool b_rev = solve(v,mid+1,r,0);
//     if (!swp) {
//         return ( a || a_rev ) && b;
//     }
//     else {
//         return (b || b_rev) && a_rev;
//     }
// }
    
// int main() {
//     int n, k;
//     cin >> n >> k;

//     for (int i = 0; i < n; i++) {

//         vector<int> v(pow(2,k));
//         for (int j = 0; j < pow(2,k); j++) cin >> v[j];
        
//         if (solve(v,0,pow(2,k)-1,0)) cout << "yes\n";
//         else cout << "no\n";
//     }

//     return 0;
// }