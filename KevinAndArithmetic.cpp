#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countTZ(long long x) {
    int count = 0;
    while (x > 0 && x % 2 == 0) {
        count++;
        x /= 2;
    }
    return count;
}
void maxArrange() {
    int n;
    cin >> n;
    vector<pair<int, long long>> arr(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        arr[i] = {countTZ(x), x};
    }
    sort(arr.rbegin(), arr.rend());
    long long sum = 0;
    int points = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].second;
        if (sum % 2 == 0) {
            points++;
            while (sum % 2 == 0) {
                sum /= 2;
            }
        }
    }
    
    cout << points << "\n";  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        maxArrange();
    }
    return 0;
}