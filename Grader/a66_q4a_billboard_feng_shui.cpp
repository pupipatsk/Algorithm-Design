#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> C;
vector<int> P;
vector<int> views;

int check_before(vector<int> &sol) {
    int passer = 0;
    return passer;
}

bool check_all(vector<int> &sol) {
    for (int strart_idx = 0; strart_idx < sol.size()-(k-1); strart_idx++) {
        bool found_pattern = false;
        for (int i = 0; i < k; i++) {
            if ( sol[strart_idx + i] == P[i]) found_pattern = true;
            else {
                found_pattern = false;
                break;
            }
        }
        if (found_pattern) return false;
    }
    return true;
}

void combi(int len, vector<int> &sol) {
    if (len < n) {
        if (check_before(sol) == 0) {
            sol[len] = 0;
            combi(len+1, sol);
        }

        if (sol[len-1] != 1) { // can't place next to each other
            if (check_before(sol) == 1) {
                sol[len] = 1;
                combi(len+1, sol);
            }
        }    
    }
    else {
        if (check_all(sol)) {
            // for (auto e : sol) cout << e;
            //     cout << '\n';
            
            int view = 0;
            for (int i = 0; i < n; i++) {
                if (sol[i] == 1) {
                    view += C[i];
                }
            }
            views.push_back(view);
        }
    }
}

int main() {
    cin >> n >> k;
    
    C.resize(n);
    for (int i = 0; i < n; i++) cin >> C[i];
    
    P.resize(k);
    for (int i = 0; i < k; i++) cin >> P[i];
    
    vector<int> sol(n);
    combi(0, sol);

    int maxView = 0;
    for (auto view : views) {
        maxView = max(maxView, view);
    }
    cout << maxView;

    return 0;
}