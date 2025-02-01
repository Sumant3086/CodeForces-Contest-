#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int prod = 0;
        
        for (int i = 0; i <= 5; ++i) {
            for (int j = 0; j <= 5 - i; ++j) {
                int k = 5 - i - j;
                int updtA = a + i;
                int updtB = b + j;
                int updtC = c + k;
                prod=max(prod, updtA * updtB * updtC);
            }
        }
        
        cout << prod << endl;
    }
    return 0;
}
