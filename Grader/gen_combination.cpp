#include <iostream>
#include <vector>

using namespace std;

void combi(int n, vector<int> &sol, int len) {
    if (len < n) {
        sol[len] = 0;
        combi(n, sol, len+1);
        sol[len] = 1;
        combi(n, sol, len+1);
    }
    else {
        for (int i = 0; i < n; i++) {
            if (sol[i]==1) cout << i+1 << " ";
        }
        cout << "." << endl;
    }
}

void combi_kn(int n, vector<int> &sol, int len, int k, int chosen) {
    if (len < n) {
        sol[len] = 0;
        combi_kn(n, sol, len+1, k, chosen);
        if (chosen < k) {
            sol[len] = 1;
            combi_kn(n, sol, len+1, k, chosen+1);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (sol[i]==1) cout << i+1 << " ";
        }
        cout << "." << endl;
    }
}

void combi_exact(int n, vector<int> &sol, int len, int k, int chosen) {
    if (len < n) {
        if (len - chosen < n - k) {
            sol[len] = 0;
            combi_exact(n, sol, len+1, k, chosen);
        }
        if (chosen < k) {
            sol[len] = 1;
            combi_exact(n, sol, len+1, k, chosen+1);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (sol[i]==1) cout << i+1 << " ";
        }
        cout << "." << endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    vector<int> sol(3);
    // combi(3, sol, 0);
    // combi_kn(4, sol, 0, 2, 0);
    combi_exact(4, sol, 0, 2, 0);

    return 0;
}