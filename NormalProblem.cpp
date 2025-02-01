#include <bits/stdc++.h>
using namespace std;
string solve(string str){
    for(char &i:str){
        if(i=='p'){
            i='q';
        }else if(i=='q'){
            i='p';
        }
    }
    reverse(str.begin(),str.end());
    return str;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
    return 0;
}
