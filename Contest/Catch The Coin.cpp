#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;
 
        if(y < -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
 
    return 0;
}