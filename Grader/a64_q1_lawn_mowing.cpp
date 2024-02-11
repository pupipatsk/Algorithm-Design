#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &v, int l, int r, int budget, int cost) {
    if (l >= r || budget <= 0) return 0;

    int amount = 0;
    for (int i = l)
    {
        int cost = k+v[l];
        if (budget >= cost) {
            amount += v[l];
            budget -= cost;
            l++;
        }
        else break;
    }

    return amount;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    while (m--)
    {
        int l, budget;
        cin >> l >> budget;

        

        cout << amount << '\n';
    }
    

    return 0;
}

// ---------- Brute Force Version. ---------- // 40 points

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);

//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> v(n);
//     for (int i = 0; i < n; i++) cin >> v[i];

//     while (m--)
//     {
//         int l, budget;
//         cin >> l >> budget;

//         int amount = 0;
//         while (budget > 0 && l < n)
//         {
//             int cost = k+v[l];
//             if (budget >= cost) {
//                 amount += v[l];
//                 budget -= cost;
//                 l++;
//             }
//             else break;
//         }

//         cout << amount << '\n';
//     }
    

//     return 0;
// }