#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    long long int ans=0LL;
    vector<long long int>arr(n);
    long long int sum=0LL;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    long long int x1=sum-y;
    long long int y1=sum-x;
    x=x1;
    y=y1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>y)break;
        long long int want1=x-arr[i]-1,want2=y-arr[i];
        int l=i+1;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=want1){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        int l1=i+1;
        int r1=n-1;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            if(arr[mid]<=want2){
                l1=mid+1;
            }else{
                r1=mid-1;
            }
        }
        ans+=l1-l;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// failed in test case 3