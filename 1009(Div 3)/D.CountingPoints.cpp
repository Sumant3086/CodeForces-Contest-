#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>x(n),r(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>r[i];
    } 
    unordered_set<long long>point;
    for(int i=0;i<n;i++){
        int xC=x[i];
        int radius=r[i];
        for(int j=xC-radius;j<=xC+radius;j++){
            int dx=j-xC;
            int dy=sqrt(radius*radius-dx*dx);
            for(int k=-dy;k<=dy;k++){
                long long key=(long long)j*1e9+k;
                point.insert(key);
            }
        }
    }
    cout<<point.size()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 
// #include <bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n,m;
//     cin>>n,m;
//     vector<int>x(n),r(n);
//     for(int i=0;i<n;i++){
//         cin>>x[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>r[i];
//     } 
//     int xmin=INT_MAX;
//     int xmax=INT_MIN;
//     for(int i=0;i<n;i++){
//         xmin=min(xmin,x[i]-r[i]);
//         xmax=max(xmax,x[i]+r[i]);
//     }
//     set<pair<int,int>>point;
//     for(int i=xmin;i<=xmax;i++){
//         for(int j=0;i<n;j++){
//             int dx=i-x[j];
//             if(dx*dx>r[j]*r[j])continue;
//             int dy=sqrt(r[j]*r[j]-dx*dx);
//             for(int k=-dy;k<=dy;k++){
//                 point.insert({i,k});
//             }
//         }
//     }
//     cout<<point.size()<<endl;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// } 
