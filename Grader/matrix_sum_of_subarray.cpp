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

int mss1(vector<int> &A, int start, int stop) { // 30 version
    
    vector<int> S(A.size());
    S[0] = 0;
    for (int i = 0; i < A.size(); i++) {
        S[i+1] = S[i] + A[i];
    }

    if (start == stop) return A[start];

    int mid = (start+stop) / 2;
    
    int r1 = mss1(A,start,mid);
    int r2 = mss1(A,mid+1,stop);

    int r3 = A[start];
    for (int p = 0; p <= mid; p++) {
        for (int q = mid+1; p < A.size(); p++) {
            
            int sum = 0;
            if (p == 0) sum = S[q];
            else sum = S[q] - S[p-1];

            if (sum > r3) r3 = sum;
        }
    }
    return max(max(r1,r2), r3);
}

int main() {
    int n; cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // cout << mss_naive(A);
    // cout << mss_prefix_sum(A);
    cout << mss1(A,0,n-1);
    
    return 0;
}