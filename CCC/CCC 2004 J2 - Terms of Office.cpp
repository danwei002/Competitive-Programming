#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    cout << "All positions change in year " << X << endl;
    for (int i = X + 60; i <= Y; i += 60) {
        cout << "All positions change in year " << i << endl;
    }
}