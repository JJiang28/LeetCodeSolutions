#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string input = "";
    cin >> input;
    int inputAmount = stoi(input) * 3;
    while(inputAmount > 0){
        string commands = "";
        cin >> commands;
        string num = "";
        cin >> num;
        int arraySize = stoi(num);
        string temp = "";
        cin >> temp;
        vector<int> meow;

        string currentNumber = "";
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '[' || temp[i] == ']' || temp[i] == ','){
                if(!currentNumber.empty()) {
                    meow.push_back(stoi(currentNumber));
                    currentNumber = "";
                }
            } else {
                currentNumber += temp[i];
            }
        }
        
        if(!currentNumber.empty()) {
            meow.push_back(stoi(currentNumber));
        }

        bool reversed = false;
        bool errorOccurred = false;
        for(int j = 0; j< commands.size(); j++){
            if(commands[j] == 'R'){
                reversed = !reversed;
            }
            if(commands[j] == 'D'){
                if(meow.size() == 0) {
                    cout << "error" << endl;
                    errorOccurred = true;
                    break;
                }
                if(reversed) {
                    meow.pop_back();
                }
                else {
                    meow.erase(meow.begin());
                }
            }
        }

         if (errorOccurred) {
            inputAmount -= 3;
            continue;
        }

        if(reversed){
            reverse(meow.begin(), meow.end());
        }
        string result = "[";
        for(int k = 0; k < meow.size(); k++) {
            if(k == meow.size() - 1) {
                result.append(to_string(meow[k]));
                continue;
            }
            result.append(to_string(meow[k]));
            result.append(",");
        }
        result.append("]");

        cout << result << endl;
        inputAmount -= 3;
    }
    
    return 0;
}
