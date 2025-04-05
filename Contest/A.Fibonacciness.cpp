#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    int maxi=0;

    int a3Fa4=a4-a2;
    int count=0;    

    if(a3Fa4==a1+a2)count++;
    count++;
    if(a5==a3Fa4+a4)count++;
    maxi=max(maxi,count);

    
    int a3Fa5=a5-a4;
    count=0;    
    if(a3Fa5==a1+a2)count++;
    if(a4==a3Fa5+a2)count++; 
    count++;
    maxi=max(maxi,count);


    int a3Fsum=a1+a2;
    count=0;    
    count++;
    if(a4==a3Fsum+a2)count++;
    if(a5==a3Fsum+a4)count++; 
    maxi=max(maxi,count);
    cout<<maxi<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}