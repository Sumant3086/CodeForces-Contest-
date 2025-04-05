#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    int startScore=n-freq.size();
    int bestScore=startScore;
    int bestL=-1;
    int bestR=-1;
    for(int l=0;l<n;l++){
        unordered_map<int,int>newF=freq;
        for(int r=l;r<n;r++){
            newF[a[r]]--;
            if(newF[a[r]]==0){
                newF.erase(a[r]);
            }
            int remL=n-(r-l+1);
            int updated=remL-newF.size();
            if(updated>bestScore || (updated==bestScore && (r-l+1)>(bestR-bestL))){
                bestScore=updated;
                bestL=l;
                bestR=r;
            }
        }
    }
    if(bestL==-1){
        cout<<"0"<<endl;
    }else{
        cout<<bestL+1<<" "<<bestR+1<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// TLE