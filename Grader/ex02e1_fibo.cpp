#include <vector>
#include <iostream>

using namespace std;

vector<int> table;

int fibo_recursion(int N) {
    if (N == 0 || N == 1) return N;
    
    if (N >= 2) return fibo_recursion(N - 1) + fibo_recursion(N - 2);
}

int fibo_TopDownDP(int N) {
    if (N == 0 || N == 1) return N;
    
    if (N >= 2) {
        if (table[N] > 0) return table[N];

        int value = fibo_recursion(N - 1) + fibo_recursion(N - 2);
        table[N] = value;
        return value;
    }
}

int fibo_ButtomUpDP(int N) {
    if (N == 0 || N == 1) return N;
    
    int fn; int f1 = 1; int f2 = 0;
    for (int i = 2; i <= N; i++) {
        fn = f1 + f2;
        
        f2 = f1;
        f1 = fn;
    }
    return fn;
}

int main() {
    int N; cin >> N;
    
    table.resize(N+1, 0);

    cout << fibo_recursion(N) <<"\n";
    cout << fibo_TopDownDP(N) <<"\n";
    cout << fibo_ButtomUpDP(N) <<"\n";

    return 0;
}