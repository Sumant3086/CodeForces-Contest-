#include <bits/stdc++.h>
using namespace std;

#define int long long

void processTestCases() {
    int testC;
    cin >> testC;

    while (testC--) {
        int a, b, c;
        cin >> a >> b >> c;
        string com;
        cin >> com;

        int currI = b - 1;
        int wPC = 0, fOC = 0;

        for (char command : com) {
            if (command == 'L') {
                currI = b;
            } else if (command == 'W') {
                if (currI <= 0) {
                    wPC++;
                }
            } else { // command == 'O'
                if (currI <= 0) {
                    fOC++;
                }
            }
            currI--;
        }

        if (wPC > c) {
            fOC++;
        }

        cout << (fOC != 0 ? "NO" : "YES") << endl;
    }
}

int32_t main() {
    processTestCases();
    return 0;
}
