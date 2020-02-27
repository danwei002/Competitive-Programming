#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, r; scanf("%d%d", &c, &r); int cx = 0; int cy = 0;
    while (true) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == 0 and y == 0) {break;}
        if (cx + x > c) {cx = c;} 
        else if (cx + x < 0) {cx = 0;} 
        else {cx += x;}
        if (cy + y > r) {cy = r;}
        else if (cy + y < 0) {cy = 0;}
        else {cy += y;}
        cout << cx << " " << cy << endl;
    }
    return 0;
}