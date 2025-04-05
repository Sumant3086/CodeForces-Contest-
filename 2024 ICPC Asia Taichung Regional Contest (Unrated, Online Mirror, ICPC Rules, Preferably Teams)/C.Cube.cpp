#include <bits/stdc++.h>
using namespace std; 
int n;
vector<vector<vector<int>>>cube;
vector<int>dp;
int backTrack(int idx,int mask){
    if(idx==n) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int minS=INT_MAX;
    
    for(int x=0;x<n;x++){
        if(mask & (1<<x))continue;
        for(int y=0;y<n;y++){
            if(mask & (1<<(y+n)))continue;
            for(int z=0;z<n;z++){
                if(mask & (1<<(z+2*n)))continue;
                int newMask=mask | (1<<x) | (1<<(y+n)) | (1<<(z+2*n));
                minS=min(minS,cube[x][y][z]+backTrack(idx+1,newMask));
            }
        }
    }
    return dp[mask]=minS;
}
int main(){
    cin>>n;
    cube.assign(n,vector<vector<int>>(n,vector<int>(n)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin>>cube[i][j][k];
            }
        }
    }
    dp.assign(1<<(3*n),-1); 
    cout<<backTrack(0,0)<<endl;
    return 0;
}


// TLE  