#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    long long pos=x;
    long long time=0;
    long long zero=0;
    long long idx=0;
    map<pair<long long,long long>,pair<long long,long long>>states;
    while(time<k){
        pair<long long ,long long>state={pos,idx};
        if(states.count(state)){
            auto[prevT,prevZ]=states[state];
            long long cycleL=time-prevT;
            long long zeroInC=zero-prevZ;
            long long rem=k-time;
            long long fullC=rem/cycleL;
            zero+=fullC*zeroInC;
            time+=fullC*cycleL;
            rem=k-time;
            for(long long i=0;i<rem;i++){
                if(time>=k)break;
                char move=s[idx];
                idx=(idx+1)%n;
                if(move=='L')pos--;
                else pos++;
                time++;
                if(pos==0){
                    zero++;
                    idx=0;
                }
            }
            break;
        }
        states[state]={time,zero};
        char move=s[idx];
        idx=(idx+1)%n;  
        if(move=='L')pos--;
        else pos++;
        time++;
        if(pos==0){
            zero++;
            idx=0;
        }
    }
    cout<<zero<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Failed in test case 3