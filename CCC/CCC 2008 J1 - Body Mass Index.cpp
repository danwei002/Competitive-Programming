#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if (a / (b * b) > 25.0) {
        cout << "Overweight";
    } else if (a / (b * b) <= 25.0 && a / (b * b) >= 18.50) {
        cout << "Normal weight";
    } else {
        cout << "Underweight";
    }
}