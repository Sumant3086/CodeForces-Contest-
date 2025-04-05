#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    unordered_set<int>idx;
    for(int  i=0;i+3<s.length();i++){
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
            idx.insert(i);
        }
    }
    while(q--){
        int i,v;
        cin>>i>>v;
        --i;

        for(int j=max(0,i-3);j<=min((int)s.length()-4,i+3);j++){
            if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='0' && s[j+3]=='0'){
            idx.erase(j);
            }
        }

        s[i]=(v==0)?'0':'1';

        for(int j=max(0,i-3);j<=min((int)s.length()-4,i+3);j++){
            if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='0' && s[j+3]=='0'){
            idx.insert(j);
            }
        }
        if(!idx.empty()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
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