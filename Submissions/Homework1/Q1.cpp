#include <iostream>
using namespace std;

int main(){
    int queryAmount = 0;
    cin >> queryAmount;

    for(int i = 0; i < queryAmount; i++) {
        long long current = 0;
        cin >> current;
        long long count = 0;
        bool impossible = false;
        while(current != 1) {
            if(current % 2 == 0){
                current = current/2;
            }
            else if(current % 3 == 0){
                current = 2 * current/3;
            }
            else if(current % 5 == 0){
                current = 4 * current/5;
            }
            else{
                impossible = true;
                break;
            }
            count++;
        }
        if(impossible) {
            cout << -1 << endl;
        }
        else {
            cout << count << endl;
        }
    }
    return 0;
}