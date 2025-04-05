#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool visited[6]={false};
    visited[a]=visited[b]=visited[c]=visited[d]=true;
    for(int i=1;i<=5;i++){
        if(!visited[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}