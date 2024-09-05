#include <iostream>
#include <set>
using namespace std;

int main(){
    int inputAmount = 0;
    cin >> inputAmount;
    for(int i = 0; i < inputAmount; i++) {
        set<char> mySet;
        int numDays = 0;
        string tasks = "";
        cin >> numDays;
        cin >> tasks;
        char current;
        bool sus = false;
        for(int j = 0; j < tasks.length(); j++) {
            if(mySet.find(tasks[j]) == mySet.end()){
                mySet.insert(tasks[j]);
                current = tasks[j];
            }
            else{
                if(current != tasks[j]) {
                    sus = true;
                }
            }
        }
        if(sus == true) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}