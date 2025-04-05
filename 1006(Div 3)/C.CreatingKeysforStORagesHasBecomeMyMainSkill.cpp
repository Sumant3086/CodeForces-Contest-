// #include <bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n;
//     long long x;
//     cin>>n>>x;
//     vector<long long>res(n);
//     if(n==1){
//         res[0]=x;
//     }else{
//         for(int i=0;i<n-1;i++){
//             res[i]=i;
//         }
//         long long currOr=0;
//         for(int i=0;i<n-1;i++){
//             currOr|=res[i];
//         }
//         if((currOr | (n-1))==x){
//             res[n-1]=n-1;
//         }else{
//             res[n-1]=0;
//             for(int j=0;j<30;j++){
//                 if((x & (1LL<<j))&& !(currOr & (1LL<<j))){
//                     res[n-1]|=(1LL<<j);
//                 }
//             }
//         }
//         long long lastOr=0;
//         for(int i=0;i<n;i++){
//             lastOr|=res[i];
//         }  
//         if(lastOr!=x){
//             res[n-1]=x;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<res[i];
//         if(i<n-1)cout<<" ";
//     }
//     cout<<endl;
// }
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long>res(n);
    if(n==1){
        res[0]=x;
    }else{
        for(int i=0;i<n-1;i++){
            res[i]=i;
        }
        long long currOr=0;
        for(int i=0;i<n-1;i++){
            currOr|=res[i];
        }
        if((currOr | (n-1))==x){
            res[n-1]=n-1;
        }else{
            res[n-1]=0;
            for(int j=0;j<30;j++){
                if((x & (1LL<<j))&& !(currOr & (1LL<<j))){
                    res[n-1]|=(1LL<<j);
                }
            }
        }
        long long lastOr=0;
        for(int i=0;i<n;i++){
            lastOr|=res[i];
        }  
        if(lastOr!=x){
            res[n-1]=x;
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i<n-1)cout<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Wrong
