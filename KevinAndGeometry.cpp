#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    map<long long, int> frq; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        frq[arr[i]]++;
    }
     
    for (auto it = frq.begin(); it != frq.end(); it++) {
        if (it->second >= 3) {   
            for (auto b = frq.begin(); b != frq.end(); b++) {
                if (b->first != it->first) {   
                    if (b->first > 2 * it->first) continue;  
                    cout << it->first << " " << it->first << " " 
                         << it->first << " " << b->first << "\n";
                    return;
                }
            }
        }
    }
     
    for (auto it = frq.begin(); it != frq.end(); it++) {
        if (it->second >= 2) {
            auto it2 = next(it);
            while (it2 != frq.end()) {
                if (it2->second >= 2) {
                    cout << it->first << " " << it->first << " " 
                         << it2->first << " " << it2->first << "\n";
                    return;
                }
                it2++;
            }
        }
    }
     
    for (auto it = frq.begin(); it != frq.end(); it++) {
        if (it->second >= 2) { 
            long long legs = it->first;
            for (auto b1 = frq.begin(); b1 != frq.end(); b1++) {
                if (b1->first == legs) continue;
                for (auto b2 = next(b1); b2 != frq.end(); b2++) {
                    if (b2->first == legs) continue; 
                    if (legs * 2 > abs(b2->first - b1->first)) {
                        cout << it->first << " " << it->first << " " 
                             << b1->first << " " << b2->first << "\n";
                        return;
                    }
                }
            }
        }
    }
    
    cout << "-1\n";
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