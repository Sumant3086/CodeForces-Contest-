#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    vector<vector<ll>> dp(n, vector<ll>(n, -1)); 
    function<ll(int,int)> calculate = [&](int l, int r) -> ll {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r]; 
        ll result = 0; 
        for (int i = l; i <= r; i++) {
            ll current = abs(a[i]);
            if (a[i] > 0) { 
                result = max(result, current + calculate(i + 1, r));
            } else { 
                result = max(result, current + calculate(l, i - 1));
            }
        }
        
        dp[l][r] = result;
        return result;
    }; 
    ll ans = calculate(0, n-1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// MLE