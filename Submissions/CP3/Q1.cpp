#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<long long> liters(n);
    long long liter = 0;
    cin >> liter;
    for(long long i = 0; i < n; i++){
        cin >> liters[i];
    }
    for(int i = 1; i < n; i++) {
        liters[i] = min(liters[i], liters[i-1] * 2);
    }
    long long ans = LLONG_MAX;
    long long curr = 0;
    for(int i = n - 1; i >= 0; i--) {
        long long vol = pow(2, i);
        long long bottles = liter/vol;
        curr += bottles * liters[i];
        liter -= bottles * vol;
        if(liter > 0) {
            ans = min(ans, curr + liters[i]);
        }
        else{
            ans = min(ans, curr);
        }
    }
    cout << ans << endl;
    return 0;
}