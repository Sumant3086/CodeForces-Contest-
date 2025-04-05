#include <bits/stdc++.h>
using namespace std;  
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,e;
        cin>>n>>s>>e;
        if(s==e){
            if(n==1){
                cout<<s<<endl;
            }else{
                cout<<-1<<endl;
            }
            continue;
        }
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>per(n);
        per[n-1]=e;
        int idx=0;
        for(int i=1;i<=n;i++){
            if(i!=e){
                per[idx++]=i;
            }
        }
        for(int i=0;i<n;i++){
            cout<<per[i]<<" ";
        }
        cout<<endl; 
    }
    return 0;
}