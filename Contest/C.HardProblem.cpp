#include <iostream>
using namespace std;
void solve(){

    int m,a,b,c;
    cin>>m>>a>>b>>c; 
    int row1=min(m,a);
    int row2=min(m,b);
    int rem=2*m-(row1+row2);
    int weCanAdd=min(rem,c);
    cout<<row1+row2+weCanAdd<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
