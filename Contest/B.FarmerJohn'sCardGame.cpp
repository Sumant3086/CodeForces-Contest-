#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>cows(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cows[i][j];
        }
        sort(cows[i].begin(),cows[i].end());
    }
    vector<pair<int,int>>order;
    for(int i=0;i<n;i++){
        order.push_back({cows[i][0],i});
    }
    sort(order.begin(),order.end());
    int currTop=-1;
    bool isPossible=true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int currCowIdx=order[j].second;
            int currCard=cows[currCowIdx][i];
            if(currCard>currTop){
                currTop=currCard;
            }else{
                isPossible=false;
                break;
            }
        }
    }
    if(isPossible){
        for(int i=0;i<n;i++){
            cout<<order[i].second+1<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
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