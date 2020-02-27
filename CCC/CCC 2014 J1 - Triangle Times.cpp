#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a + b + c != 180) {
        cout << "Error";
    } else {
        if (a == 60 && a == b && b == c) {
            cout << "Equilateral";
        } else if (a == b || a == c || b == c) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
    }
}