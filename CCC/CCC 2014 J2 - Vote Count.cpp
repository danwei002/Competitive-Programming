#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int a = 0;
    int b = 0;
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        if (x == 'A') {
            a++;
        } else {
            b++;    
        }
    }
    
    if (a == b) {
        cout << "Tie";
    } else if (a < b) {
        cout << "B";
    } else {
        cout << "A";
    }
}