// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;  
//     while (t--) {
//         int n;
//         cin >> n;  
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }

//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=a[i];
//     }
//     if(sum%2!=0){
//         cout<<"YES"<<endl;
//     }else{
//         cout<<"NO"<<endl;
//     }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }

        sort(a.begin(), a.end(), greater<int>());

        int mx = 0;  
        bool aTrn = true;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= mx) {
                mx = a[i];  
                aTrn = !aTrn;  
            }
        }

        if (!aTrn) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl; 
        }
    }
    return 0;
}
