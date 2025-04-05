#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long dashC=0,underscoreC=0;
    for(char c:s){
        if(c=='-'){
            dashC++;
        }else{
            underscoreC++;
        }
    }
    if(dashC<2 || underscoreC<1){
        cout<<0<<endl;
    } else{
        long long firstH=dashC/2;
        long long secondH=dashC-firstH;
        cout<<firstH*underscoreC*secondH<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}