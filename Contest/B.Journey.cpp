#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,a,b,c;
    cin>>n>>a>>b>>c; 
    long long cycle=a+b+c; 
    long long day=0;
    day=(n-1)/cycle*3;
    n-=(n-1)/cycle*cycle;
    if(n<=a)day++;
    else if(n<=a+b)day+=2;
    else day+=3;
    cout<<day<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}