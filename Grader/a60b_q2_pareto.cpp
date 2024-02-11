#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> A;

vector<int> pareto(int l,int r) {
    if (l == r) return {l}; // 1 point is also paretofrontier

    // Divide by x coordinate (because A is sorted by x)
    int mid = (l+r) / 2;
    vector<int> L = pareto(l,mid);
    vector<int> R = pareto(mid+1,r);

    vector<int> ret; // [index, ...]
    int y_max = 0;
    for (auto &i : R) {
        int y = A[i].second;
        y_max = max(y_max, y);
        ret.push_back(i);
    }
    for (auto &i : L) {
        int y = A[i].second;
        if (y >= y_max) ret.push_back(i);
    }

    return ret;
}

int main() {
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A.push_back( {x,y} );
    }
    sort(A.begin(), A.end());

    cout << pareto(0,N-1).size();
    
    return 0;
}