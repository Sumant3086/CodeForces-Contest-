#include <bits/stdc++.h>
using namespace std;
void OR(int n,int k,vector<vector<int>>&countries){
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            countries[i][j]|=countries[i-1][j];
        }
    }
}
bool satisfy(int m,const vector<tuple<int,char,int>>& query,const vector<int>& country){
    for(int i=0;i<m;i++){
        int r;
        char o;
        int c;
        tie(r,o,c)=query[i];
        int rv=country[r-1];
        if((o=='<' && rv>=c) || (o=='>' && rv<=c)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<int>>countries(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>countries[i][j];
        }
    }
    OR(n,k,countries);
    while(q--){ 
        int m;
        cin>>m;
        vector<tuple<int,char,int>>query(m);
        for(int i=0;i<m;i++){
            int r;
            char o;
            int c;
            cin>>r>>o>>c;
            query[i]=make_tuple(r,o,c);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(satisfy(m,query,countries[i])){
                ans=i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}