#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>>plants(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x>y){
            plants.push_back({y,x});
        }
    }
    sort(plants.begin(),plants.end());
    int spent=0;
    int money=p;
    for(auto& i:plants){
        int y=i.first;
        int x=i.second;
        if(spent+y<=p){
            spent+=y;
            money+=(x-y);
        }
    }
    cout<<spent<<" "<<money<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

