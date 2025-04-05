#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int x=a+b-1;
        pq.push(x);
    }
    cout<<pq.top()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}