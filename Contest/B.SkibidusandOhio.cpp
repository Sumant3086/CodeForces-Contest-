#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s; 
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            cout<<1<<endl;
            goto next;
        }
    }
    cout<<s.size()<<endl;
    next:;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 