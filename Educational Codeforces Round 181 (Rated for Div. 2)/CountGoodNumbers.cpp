#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long l, r;

long long count_multiples(long long a, long long l, long long r) {
    return r / a - (l - 1) / a;
}

long long inclusion_exclusion(long long l, long long r) {
    vector<int> primes = {2, 3, 5, 7};
    int n = primes.size();
    long long total = r - l + 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int bits = __builtin_popcount(mask);
        long long product = 1;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                product *= primes[i];
                if (product > r) break;
            }
        }
        if (product > r) continue;
        long long cnt = count_multiples(product, l, r);
        if (bits % 2 == 1) {
            total -= cnt;
        } else {
            total += cnt;
        }
    }
    return total;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << inclusion_exclusion(l, r) << endl;
    }
    return 0;
}