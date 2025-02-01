#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> height(n);
        for(int i=0;i<n;++i){
            cin>>height[i];
        }
        long long int result=0;
        for(int i=0;i<n;++i){
            result=max(result, height[i]+i);
        }
        cout<<result<<endl;
    }

    return 0;
}
 