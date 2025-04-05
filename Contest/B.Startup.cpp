#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < k; i++) {
            int brand, cost;
            cin >> brand >> cost;
            m[brand].push_back(cost);
        }
        vector<int> ans;
        for (auto& i : m) {
            int totalCost = accumulate(i.second.begin(), i.second.end(), 0);
            ans.push_back(totalCost);
        }
        sort(ans.rbegin(), ans.rend());
        int totalProfit = 0;
        int idx = 0;
        while (n > 0 && idx < ans.size()) {
            totalProfit += ans[idx];
            idx++;
            n--;
        }
        cout << totalProfit << endl;
    }
    return 0;
}
