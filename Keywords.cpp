#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main(){
    int number = 0;
    cin >> number;
    set<string> meow;
    cin.ignore();

    for(int i = 0; i < number; i++) {
        string keyword = "";
        getline(cin, keyword);
        for(int j = 0; j < keyword.size(); j++) {
            if(isalpha(keyword[j])) {
                keyword[j] = tolower(keyword[j]);
            }
            if(keyword[j] == '-'){
                keyword[j] = ' ';
            }
        }
        meow.insert(keyword);
    }
    cout << meow.size() << endl;
    return 0;
}