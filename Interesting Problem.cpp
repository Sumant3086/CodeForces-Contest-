#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int operations = 0;
        int i=0;
        while(i<n-1){
            if(a[i] == i + 1) {
                operations++;
                i+=2;
            }else{
                i++;
            }
        }
        cout<<operations<<endl;
    }
    return 0;
}