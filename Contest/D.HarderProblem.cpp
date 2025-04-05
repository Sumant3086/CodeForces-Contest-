#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        // For the first position, we can use any number
        if(i == 0) {
            b[i] = a[i];
            continue;
        }
        
        // Count frequencies in the prefix
        map<int, int> freq;
        for(int j = 0; j < i; j++) {
            freq[b[j]]++;
        }
        
        // Find the maximum frequency
        int maxFreq = 0;
        for(auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        // If a[i] doesn't appear enough times, make it appear maxFreq times
        if(freq[a[i]] < maxFreq) {
            b[i] = a[i];
        }
        // If some other number appears more times, use a[i]
        else {
            // We can use any number that keeps a[i] as a mode
            // Using a[i] is the safest choice
            b[i] = a[i];
        }
    }
    
    // Print result
    for(int x : b) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}