#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    long long count2=0;
    long long count3=0;
    long long sum=0;
    for(auto i:s){
        if(i=='2')count2++;
        if(i=='3')count3++;
        sum+=i-'0';
    }
    long long diff=(9-sum%9)%9;
    for(long long b=0;b<=count3;b++){
        long long newD=(diff-6LL*b)%9;
        if(newD<0){
            newD+=9;
        }
        long long a=(newD*5)%9;
        if(a<=count2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 