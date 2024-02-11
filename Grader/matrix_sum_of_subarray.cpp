#include <iostream>
#include <vector>

using namespace std;

int mss_naive(vector<int> &A) {
    int max = A[0];
    for (int start = 0; start < A.size(); start++) {
        for (int stop = start+1; stop < A.size(); stop++) {
            
            int sum = 0;
            for (int i = start; i <= stop; i++) {
                sum += A[i];
            }
            if (sum > max) max = sum;
        }
    }
    return max;
}

int mss_prefix_sum(vector<int> &A) {
    // sigma(i = p to q) A[i] = S[q] - S[p-1]

    vector<int> S(A.size());
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        S[i] = sum;
    }

    int max = A[0];
    for (int p = 0; p < S.size(); p++) {
        for (int q = p; q < S.size(); q++) {
            
            int sum = 0;
            if (p == 0) sum = S[q];
            else sum = S[q] - S[p-1];
            
            if (sum > max) max = sum;
        }
    }
    return max;
}

int main() {
    int n; cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // cout << mss_naive(A);
    cout << mss_prefix_sum(A);
    
    return 0;
}