#include <bits/stdc++.h>

using namespace std;

int main() {
    int H;
    scanf("%d", &H);
    
    int num = 1;
    for (int i = 0; i < H / 2 + 1; i++) {
        for (int j = 0; j < num; j++) {
            cout << "*";
        }
        
        for (int j = 0; j < (2 * H) - (2 * num); j++) {
            cout << " ";
        }
        
        for (int j = 0; j < num; j++) {
            cout << "*";
        }
        num += 2;
        cout << endl;
    }
    
    num -= 4;
    for (int i = 0; i < H / 2; i++) {
         for (int j = 0; j < num; j++) {
            cout << "*";
        }
        
        for (int j = 0; j < (2 * H) - (2 * num); j++) {
            cout << " ";
        }
        
        for (int j = 0; j < num; j++) {
            cout << "*";
        }
        num -= 2;
        cout << endl;
    }
}