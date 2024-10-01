#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct CompareSum {
    bool operator()(pair<long long, long long> p1, pair<long long, long long> p2) {
        return (p1.first + p1.second) > (p2.first + p2.second);
    }
};  

int main(){
    string limits = " ";
    getline(cin, limits);
    istringstream s(limits);
    long long helpNeeded, coworkerCount = 0;
    s >> helpNeeded >> coworkerCount;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, CompareSum> heap;
    for(long long i = 0; i < coworkerCount; i++) {
        string temp = "";
        getline(cin, temp);
        istringstream p(temp);
        long long initial, additional = 0;
        p >> initial >> additional;
        heap.push({initial, additional});
    }
    for(long long i = 0; i < helpNeeded; i++) {
        pair<long long,long long> current = heap.top();
        heap.pop();
        long long newValue = current.first + current.second;
        heap.push({newValue, current.second});
    }
    long long maxAnnoyance = 0;
    while(!heap.empty()) {
        pair<long long, long long> current = heap.top();
        heap.pop();
        maxAnnoyance = max(maxAnnoyance, current.first);
    }
    cout << maxAnnoyance << endl;
    return 0;
}