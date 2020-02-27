#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B; cin >> A >> B;
    int diff = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A.at(i) != B.at(i)) {diff++;}
        if (diff > 1) {cout << "LARRY IS DEAD!\n"; return 0;}
    }
    
    if (diff == 1) {
        cout << "LARRY IS SAVED!\n";
    } else {
        cout << "LARRY IS DEAD!\n";
    }
    return 0;
}