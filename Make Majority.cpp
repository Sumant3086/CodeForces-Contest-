#include <iostream>
#include <string>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long count[2]={0};   
    string res;
    res.push_back(s[0]);  
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1] && s[i]=='0') continue;   
        res.push_back(s[i]);
    }
    for(int i=0;i<res.size();i++){
        count[res[i]-'0']++;  
    }
    cout<<((count[1]>count[0])?"Yes":"No")<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
