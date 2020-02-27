#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int y, m, d; scanf("%d%d%d", &y, &m, &d);
        if (y > 1989) {cout << "No" << endl;}
        else if (y < 1989) {cout << "Yes" << endl;}
        else {
            if (m > 2) {cout << "No" << endl;}
            else if (m < 2) {cout << "Yes" << endl;}
            else {
                if (d > 27) {cout << "No" << endl;}
                else if (d <= 27) {cout << "Yes" << endl;}
            }
        }    
    }
    return 0;
}