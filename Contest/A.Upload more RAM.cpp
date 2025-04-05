#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int result=0;
        while(x!=1){
            result+=y;
            x--;
        }
        result+=1;
        cout<<result<<endl;
    }
    return 0;
}