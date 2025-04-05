#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int  left=0;
    int right=n-1;
    int count=0;
    while(left<right){
        int sum=arr[left]+arr[right]; 
        if(sum==k){
            count++;
            left++; 
            right--;
        }else if(sum>k){
            right--;
        }else{
            left++;
        }
    }
        cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}