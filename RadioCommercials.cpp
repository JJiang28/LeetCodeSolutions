#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string info = "";
    string commercials= "";
    getline(cin, info);
    getline(cin, commercials);
    istringstream s(info);
    int commercialCount, cost = 0;
    s >> commercialCount >> cost;
    vector<int> commercialList;
    istringstream ss(commercials);
    int meow = 0;
    for(int i = 0; i < commercialCount; i++) {
        ss >> meow;
        meow -= cost;
        commercialList.push_back(meow);
    }
    int curr = commercialList[0];
    int highest = commercialList[0];
    for(int i = 1; i < commercialCount; i++) {
        curr = max(commercialList[i], curr + commercialList[i]);
        highest = max(curr, highest);
    }
    cout << highest << endl;
    return 0;
}