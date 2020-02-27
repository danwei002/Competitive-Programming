#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 or n == 9 or n == 10) {
        cout << 1;
    } else if (n == 2 or n == 3 or n == 7 or n == 8) {
        cout << 2;
    } else if (n == 4 or n == 5 or n == 6) {
        cout << 3;
    } 
}