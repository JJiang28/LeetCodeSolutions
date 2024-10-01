#include <iostream>
#include <stack>
using namespace std;

int main(){
    string game = "";
    cin >> game;
    int playerOneWin = 0;
    stack<char> deleteable;
    for(int i = 0; i < game.size(); i++) {
        if(deleteable.size() != 0) {
            if(deleteable.top() == game[i]) {
                deleteable.pop();
                playerOneWin += 1;
                continue;
            }
        }
        deleteable.push(game[i]);
    }
    if(playerOneWin % 2 == 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}