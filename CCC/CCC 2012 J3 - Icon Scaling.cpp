#include <bits/stdc++.h>

using namespace std;

int main() {
    string l1 = "*x*";
    string l2 = " xx";
    string l3 = "* *";
    int scale;
    
    cin >> scale;

    for (int i = 0; i < scale; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < scale; k++) {
                cout << l1.at(j);
            }
        }
        cout << endl;
    }
    
    for (int i = 0; i < scale; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < scale; k++) {
                cout << l2.at(j);
            }
        }
        cout << endl;
    }
    
    for (int i = 0; i < scale; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < scale; k++) {
                cout << l3.at(j);
            }
        }
        cout << endl;
    }
}