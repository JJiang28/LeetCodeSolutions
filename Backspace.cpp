#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input = "";
    cin >> input;
    string result = "";

    stack<char> s;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '<') {
            if(s.empty()) {
                return 0;
            }
            s.pop();
            continue;
        }
         s.push(input[i]);
    }
    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}