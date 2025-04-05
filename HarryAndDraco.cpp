#include <bits/stdc++.h>
using namespace std;
string solve(int n,int p,int m,int x){
    if(p==x)return "Gryffindor";
    int moves=abs(x-p)/m;
    return (abs(x-p)%m==0)?(moves%2==0?"Slytherin":"Gryffindor"):"Draw";

}
int main(){
    int n,p,m,x;
    cin>>n>>p>>m>>x;
    cout<<solve(n,p,m,x)<<endl;
    return 0;
}