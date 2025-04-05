#include <bits/stdc++.h>
using namespace std;
bool isU(const string& s){
    string r=s;
    reverse(r.begin(),r.end());
    return s<r;
}
bool solve(const string& s,int k){
    if(isU(s)){
        return true;
    }
    if(k==0){
        return false;
    }
    int n=s.length();
    bool same=true;
    for(int i=1;i<n;i++){
        if(s[i]!=s[0]){
            same=false;
            break;
        }
    }
    if(same){
        return false;
    }
    return k>=1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(solve(s,k)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        } 
    }
    return 0;
} 

