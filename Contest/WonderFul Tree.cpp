#include <bits/stdc++.h>
using namespace std; 
#define ALL(a) (a).begin(), (a).end()
#define FIRST first 
#define SECOND second 
#define MOD 1000000007
#define MAXN 5010  
typedef long long ll; 
ll dp[MAXN][MAXN];
ll countArr[MAXN];
#define DP dp[index][asc]
ll calculate(ll index, ll asc) {
    if (asc < 0) return -2;
    if (!index) return asc ? -2 : 0;
    if (~DP) return DP;
    if (countArr[index]) DP = calculate(index - 1, asc - 1); 
    else DP = calculate(index - 1, asc);
    if (calculate(index - 1, asc) != -2 && calculate(index - 1, asc) + countArr[index] <= asc) {
        if (DP == -2 || calculate(index - 1, asc) + countArr[index] < DP) DP = calculate(index - 1, asc) + countArr[index];
    }
    return DP;
}
#define READ_INT(x) int x; cin >> x;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i > (b); --i)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    READ_INT(testCases)
    while (testCases--) {
        READ_INT(n)
        FOR(i, 0, n + 1) fill_n(dp[i], n + 1, -1);
        FOR(i, 0, n) {
            READ_INT(x)
            countArr[x]++;
        }
        ll result = n;
        FORD(i, n, -1) if (calculate(n, i) != -2) result = i;
        cout << result << endl;
        fill_n(countArr, n + 1, 0ll);
    }
    return 0;
}
