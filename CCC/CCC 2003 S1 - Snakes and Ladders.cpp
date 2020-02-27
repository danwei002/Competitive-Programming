#include <bits/stdc++.h>

using namespace std;

int main() {
    int start = 1;
    while (true) {
        int roll;
        cin >> roll;
        
        if (roll == 0) {
            cout << "You Quit!" << endl;
            return 0;
        }
        
        if (start + roll > 100) {
            cout << "You are now on square " << start << endl;
            continue;
        }
        
        start += roll;
        if (start == 9) {
            start = 34;
        }
        
        if (start == 40) {
            start = 64;
        }
        
        if (start == 67) {
            start = 86;
        }
        
        if (start == 99) {
            start = 77;
        }
        
        if (start == 90) {
            start = 48;
        }
        
        if (start == 54) {
            start = 19;
        }
        
        if (start == 100) {
            cout << "You are now on square " << start << endl;
            cout << "You Win!" << endl;
            return 0;
        }
        
        cout << "You are now on square " << start << endl;
    }
}