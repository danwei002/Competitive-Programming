#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    int turn = 1;
    int played = 0;
    while (n > 0) {
        a++;
        played++;
        if (a == 35) {
            n += 30;
            a = 0;
        }
        n--;
        if (n == 0) {
            break;
        }
        b++;
        played++;
        if (b == 100) {
            n += 60;
            b = 0;
        }
        n--;
        if (n == 0) {
            break;
        }
        c++;
        played++;
        if (c == 10) {
            n += 9;
            c = 0;
        }
        n--;
    }
    cout << "Martha plays " << played << " times before going broke.";
}
