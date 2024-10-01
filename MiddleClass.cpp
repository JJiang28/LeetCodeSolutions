#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long input = 0;
    cin >> input;
    for(long long i = 0; i < input; i++) {
        long long n, x = 0;
        cin >> n >> x;
        vector<long long> meow(n);
        for(long long j = 0; j < n; j++) {
            cin >> meow[j];
        }
        sort(meow.begin(), meow.end(), greater<long long>());
        long long curr = 0;
        long long res = 0;
        for(long long k = 0; k < meow.size(); k++) {
            curr += meow[k];
            if(curr >= x * (k+1)) {
                res = k+1;
            }
            else {
                break;
            }
        } 
        cout << res << endl;
    }
    return 0;
}