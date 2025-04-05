#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dis=0;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            dis++;
        }
    }
    int minD=dis;
    for(int i=0;i<n/2;i++){
        int left=i;
        int right=n-i-1;
        int curr=dis;
        if(left>0 && arr[left]==arr[left-1])curr--;
        if(right<n-1 && arr[right]==arr[right+1])curr--;
        if(right-left==1 && arr[left]==arr[right])curr--;

        swap(arr[left],arr[right]);
        
        if(left>0 && arr[left]==arr[left-1])curr++;
        if(right<n-1 && arr[right]==arr[right+1])curr++;
        if(right-left==1 && arr[left]==arr[right])curr++;
        
        minD=min(minD,curr);
        swap(arr[left],arr[right]);
    }
    cout<<minD<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



// incorrect