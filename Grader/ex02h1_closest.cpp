#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distance(pair<int, int> a, pair<int,int> b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx*dx + dy*dy;
}

int solve(vector<pair<int,int>> &X, vector<pair<int,int>> &Y) {
    int N = X.size(); // amount of points

    if (N == 1) return 2e9;
    if (N == 2) return distance(X[0], X[1]);

    // divided points to 2 side
    int mid = (N - 1) / 2; // middle idx // 4:[0,1=mid, 2,3]

    vector<pair<int,int>> XL, XR;
    for (int i = 0; i <= mid; i++) XL.push_back(X[i]);
    for (int i = mid+1; i < N; i++) XR.push_back(X[i]);
    vector<pair<int,int>> YL, YR;
    for (auto &p : Y) {
        int x = p.first;
        int y = p.second;
        if (x <= XL.back().first) YL.push_back(p);
        else YR.push_back(p);
    }

    // closet pair is in left or right side
    int minDist = min(solve(XL,YL), solve(XR,YR));

    // or closet pair is in strip
    vector<pair<int,int>> strip;
    for (auto &p : Y) {
        int x = p.first;
        int x_bound = XL.back().first;
        if ( (x-x_bound)*(x-x_bound) < minDist) { // distance is in degree 2 (x^2)
            strip.push_back(p);
        }
    }
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i+1; j < strip.size(); j++) {
            int y_i = strip[i].second;
            int y_j = strip[j].second;
            
            if ( (y_i - y_j)*(y_i - y_j) >= minDist) break;

            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

int main() {
    int n; cin >> n;

    vector<pair<int,int>> X, Y;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        X.push_back( {x,y} );
        Y.push_back( {y,x} );
    }
    sort(X.begin(), X.end()); 
    sort(Y.begin(), Y.end()); 
    for (auto &p : Y) {
        swap(p.first, p.second);
    }

    cout << solve(X,Y);
    
    return 0;
}