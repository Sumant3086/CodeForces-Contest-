#include <iostream>
using namespace std;
int solve(int n, int k) {
    int diogonals=n*2-2;
    if(k==0)return 0;
    if(k<=n)return 1;
    int count=1,sum=n;
    for(int i=0;i<diogonals/2;i++){
        n--;
        for(int j=0;j<2;j++){
            count++;
            sum+=n;
            if(sum>=k)return count;
        }
    }
    return count;
}

int main() {
    int s;
    cin>>s;
    while(s--){
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}
