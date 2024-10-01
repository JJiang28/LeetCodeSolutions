#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long input = 0;
    cin >> input;
    vector<long long> people(input);
    for(long long i = 0; i < input; i++) {
        long long meow = 0;
        cin >> meow;
        people[i] = meow;
    }
    sort(people.begin(), people.end());
    long long res = 0;
    long long total = 0;
    for(auto e: people) {
        if(total > e) {
            res++;
            continue;
        }
        total += e;
    }
    cout << input - res << endl;
    return 0;
}