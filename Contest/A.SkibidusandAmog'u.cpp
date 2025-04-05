#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    s.replace(s.size()-2,2,"i");
    cout<<s<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 