#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long input = 0;
    cin >> input;
    vector<pair<long long, long long>> meow(input); //batman
    vector<pair<long long, long long>> overlapCount(input); 
    vector<long long> removableLessons;
    long long totalOverlaps = 0;

    for(long long i = 0; i < input; i++) {
        long long start = 0;
        long long end = 0;
        cin >> start >> end;
        meow[i] = {start, end};
        overlapCount[i] = {0, i + 1};
        //cout << meow.at(i).first << " " << meow.at(i).second;
    }
    for(long long i = 0; i < input; i++) {
        for(long long j = 0; j < i; j++) {
            if(meow[i].first<meow[j].second && meow[j].first<meow[i].second){
                overlapCount[i].first++;
                overlapCount[j].first++;
                totalOverlaps++;
            }
        }
    }
    
    for(auto p: overlapCount) {
        if (p.first == totalOverlaps) {
            removableLessons.push_back(p.second);
        }
    }
    
    long long numOfWays = removableLessons.size();
    cout << numOfWays << '\n';

    for(auto lesson: removableLessons) {
        cout << lesson << ' ';
    }
    return 0;
}