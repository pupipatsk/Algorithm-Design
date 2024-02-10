#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<pair<int,int>> vop;
    for (int i = 0; i < N; i++){
        int no, amount;
        cin >> no >> amount;
        vop.push_back({no, amount});
    }
    sort(vop.begin(), vop.end());

    map<int,int> mp;
    int sum = 0;
    for (auto &p : vop) {
        int no = p.first;
        int amount = p.second;

        sum += amount;
        mp[sum] = no;
    }
    
    for (int i = 0; i < Q; i++) {
        int Qidx;
        cin >> Qidx;

        auto it = mp.lower_bound(Qidx);
        cout << it->second << "\n";
    }

    return 0;
}