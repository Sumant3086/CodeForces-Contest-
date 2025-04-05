#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void processTestCase() {
    int nE, subArrS;
    cin >> nE >> subArrS;
    vector<int> ele(subArrS);

    for (int i = 0; i < subArrS; ++i) {
        cin >> ele[i];
    }

    sort(ele.begin(), ele.end());

    int res = nE - ele[subArrS - 1];
    for (int i = 0; i < subArrS - 1; ++i) {
        res += (ele[i] - 1);
    }
 
    cout << res << '\n';
}

int main() {
    int testC;
    cin >> testC;  
    while (testC--) {
        processTestCase();
    }
    return 0;
}
