#include <iostream>
#include <map>
using namespace std;

int main() {
    int input;
    cin >> input;
    map<int, long long> count;
    for(int i = 0; i < input; ++i) {
        int num;
        cin >> num;
        count[num]++;
    }
    long long result = 0;
    for(auto entry : count) {
        int t = entry.first;
        if (t > 0 && count.find(-t) != count.end()) {
            result += entry.second * count[-t];
        }
    }
    if(count[0] > 1){
        result += count[0] * (count[0] - 1) / 2;
    }
    cout << result << endl;
    return 0;
}
