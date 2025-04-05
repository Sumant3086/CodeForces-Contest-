#include <iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    string t="";
    if(s[0]=='1')count++;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            count++;
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
// #include <iostream>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     int count=0;
//     string t="";
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='1'){
//             count++;
//             t+=s.substr(i);
//             s=s.substr(0,i);
//             break;
//         }
//     }
//     for(int i=0;i<t.length();i++){
//         if(t[i]=='0'){
//             count++;
//             s+=t.substr(i);
//             t=t.substr(0,i);
//             break;
//         }
//     }

// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }