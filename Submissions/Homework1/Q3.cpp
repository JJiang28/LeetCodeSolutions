#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int input = 0;
    while(true) {
        cin >> input;
        if(input == -1) {
            break;
        }
        cin.ignore();
        int totalTime = 0;
        int distance = 0;
        for(int i = 0; i < input; i++){
            string dataSet = "";
            getline(cin, dataSet);
            istringstream s(dataSet);
            int speed, timeElapsed;
            s >> speed >> timeElapsed;
            distance += (timeElapsed - totalTime) * speed;
            totalTime = timeElapsed;
        }
        cout << distance << " miles" << endl;
    }
    return 0;
}