#include <iostream>
#include <vector>

using namespace std;

vector<int> matrix_mod(const vector<int> &M, int k) {
    vector<int> M_modk(M.size());
    for (int i = 0; i < M.size(); i++) {
        M_modk[i] = M[i] % k;
    }
    return M_modk;
}

vector<int> matrix_multiply(const vector<int> &M, const vector<int> &N) {
    // 2D Matrix
    int M11 = M[0]; int M12 = M[1]; int M21 = M[2]; int M22 = M[3];
    int N11 = N[0]; int N12 = N[1]; int N21 = N[2]; int N22 = N[3];
    return {M11*N11 + M12*N21, M11*N12 + M12*N22,
            M21*N11 + M22*N21, M21*N12 + M22*N22}; // MN
}

vector<int> matrix_multiply_mod(const vector<int> &M, const vector<int> &N,int k) {
    vector<int> M_modk = matrix_mod(M,k);
    vector<int> N_modk = matrix_mod(N,k);
    return matrix_mod(matrix_multiply(M_modk,N_modk), k); // (MN) mod k = ( (M mod k) * (N mod k) ) mod k
}

vector<int> matrix_power_mod(const vector<int> &A, int n, int k) {
    if (n == 1) return matrix_mod(A,k);

    vector<int> half_power = matrix_power_mod(A, n/2, k);
    
    vector<int> result = matrix_multiply_mod(half_power, half_power, k);
    if (n%2 == 1) result = matrix_multiply_mod(result, A, k);

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(4); // [a,b,c,d]
    for (int i = 0; i < 4; i++) cin >> A[i];
    
    vector<int> ans = matrix_power_mod(A, n, k);

    for (auto &e : ans) cout << e << " ";

    return 0;
}

// ---------- Brute Force version, 60 points ----------

// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> matrix_mod(const vector<int> &M, int k) {
//     vector<int> M_modk(M.size());
//     for (int i = 0; i < M.size(); i++) {
//         M_modk[i] = M[i] % k;
//     }
//     return M_modk;
// }

// vector<int> matrix_multiply(const vector<int> &M, const vector<int> &N) {
//     // 2D Matrix
//     int M11 = M[0]; int M12 = M[1]; int M21 = M[2]; int M22 = M[3];
//     int N11 = N[0]; int N12 = N[1]; int N21 = N[2]; int N22 = N[3];
//     return {M11*N11 + M12*N21, M11*N12 + M12*N22,
//             M21*N11 + M22*N21, M21*N12 + M22*N22}; // MN
// }

// vector<int> matrix_multiply_mod(const vector<int> &M, const vector<int> &N,int k) {
//     vector<int> M_modk = matrix_mod(M,k);
//     vector<int> N_modk = matrix_mod(N,k);
//     return matrix_mod(matrix_multiply(M_modk,N_modk), k); // (MN) mod k = ( (M mod k) * (N mod k) ) mod k
// }

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> A(4); // [a,b,c,d]
//     for (int i = 0; i < 4; i++) cin >> A[i];
    
//     vector<int> ans = A;
//     for (int i = 1; i < n; i++) {
//         ans = matrix_multiply_mod(ans,A,k);
//     }

//     for (auto &e : ans) cout << e << " ";

//     return 0;
// }