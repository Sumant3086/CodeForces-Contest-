#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int test) {
    int n;
    cin>>n;
    vector<long long> array(n);
    for (int i=0;i<n;i++) 
    cin>>array[i];
    
    long long result=0,x=0;
    for(int i=1;i<n;i++){
        if (array[i]<array[i-1]){
            result+=array[i-1]-array[i];
            x=max(x,array[i-1]-array[i]);
            array[i]=array[i-1];
        }
    }
    result+=x;
    cout<<result<<'\n';
}

int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        solve(i+1);
    }
    return 0;
}