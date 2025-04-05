// #include <bits/stdc++.h> 
// using namespace std; 
// typedef long long ll;
// ll countValidY(ll x,ll k,ll l2, ll r2){
//     ll count=0;
//     ll y=x;  
//     while(y<=r2){
//         if(y>=l2){
//             count++;
//         }
//         if(y>r2/k)break;
//         y*=k;
//     }    
//     return count;
// }

// void solve(){
//     ll k,l1,r1,l2,r2;
//     cin>>k>>l1>>r1>>l2>>r2;
//     ll ans=0;
//     for(ll x=l1;x<=r1;x++){ 
//         ans+=countValidY(x,k,l2,r2);
//     }
//     cout<<ans<<endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }

// // #include <iostream>
// // #include <vector>
// // using namespace std;
// // typedef long long ll;

// // // Function to find all powers of k * x that lie within [l2, r2]
// // ll countValidY(ll x, ll k, ll l2, ll r2) {
// //     ll count = 0;
// //     ll y = x;  // Start with n = 0, so y = x * k^0
    
// //     // Keep multiplying by k until we exceed r2
// //     while (y <= r2) {
// //         if (y >= l2) {  // If y is within range [l2, r2]
// //             count++;
// //         }
// //         // Check if multiplying by k would overflow
// //         if (y > r2/k) break;
// //         y *= k;
// //     }
    
// //     return count;
// // }

// // void solve() {
// //     ll k, l1, r1, l2, r2;
// //     cin >> k >> l1 >> r1 >> l2 >> r2;
    
// //     ll answer = 0;
    
// //     // For each x in range [l1, r1]
// //     for (ll x = l1; x <= r1; x++) {
// //         // Count how many valid y values exist for this x
// //         answer += countValidY(x, k, l2, r2);
// //     }
    
// //     cout << answer << "\n";
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
    
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         solve();
// //     }
// //     return 0;
// // }


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Binary search to find largest power n where k^n * x <= r
ll findMaxPower(ll x, ll k, ll r) {
    if (x > r) return -1;
    ll left = 0, right = 60;  // log_2(10^18) ≈ 60
    
    while (left < right) {
        ll mid = (left + right + 1) / 2;
        ll val = x;
        bool overflow = false;
        
        // Calculate k^mid * x carefully
        for (int i = 0; i < mid && !overflow; i++) {
            if (val > r/k) overflow = true;
            else val *= k;
        }
        
        if (overflow || val > r) right = mid - 1;
        else left = mid;
    }
    return left;
}

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    ll ans = 0;
    
    // For each x in [l1, r1], find how many powers of k make y fall in [l2, r2]
    for (ll x = l1; x <= r1; x++) {
        // Find max power for upper bound r2
        ll maxPow = findMaxPower(x, k, r2);
        if (maxPow == -1) continue;
        
        // Find min power for lower bound l2
        ll minPow = findMaxPower(x, k, l2 - 1) + 1;
        
        // If valid range exists
        if (minPow <= maxPow) {
            ans += (maxPow - minPow + 1);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}