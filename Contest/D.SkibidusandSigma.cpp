#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to calculate the score of an array
int calS(const vector<int>& arr) {
    ll sum = 0;
    int prefS = 0;
    for (int i : arr) {
        prefS += i;
        sum += prefS;
    }
    return sum;
}

// Function to solve each test case
void solve() {
    int n, m;
    cin >> n >> m;
    
    // Initialize the array correctly
    vector<vector<int>> array(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }
    
    // Calculate total sum and score for each array
    vector<pair<ll, ll>> info;
    for (int i = 0; i < n; i++) {
        ll tot = 0;
        for (int num : array[i]) {
            tot += num;
        }
        ll score = calS(array[i]);
        info.push_back({tot, score});
    }
    
    // Sort arrays in descending order of total sum
    sort(info.begin(), info.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first > b.first;
    });
    
    // Concatenate arrays in the sorted order
    vector<int> con;
    for (auto& p : info) {
        int idx = &p - &info[0]; // Get the index of the array
        con.insert(con.end(), array[idx].begin(), array[idx].end());
    }
    
    // Calculate the final score
    ll final = calS(con);
    cout << final << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}