#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    long long inputCount = 0;
    cin >> inputCount;
    unordered_map<string, int> usernames;

    for(int i = 0; i < inputCount; i++) {
        string userN = " ";
        cin >> userN;
        if(usernames[userN] == 0) {
            cout << "OK" << endl;
            usernames[userN] += 1;
        }
        else {
            string temp = userN;
            cout << temp.append(to_string(usernames[userN])) << endl;
            usernames[userN] += 1;
        }
    }
    return 0;
}