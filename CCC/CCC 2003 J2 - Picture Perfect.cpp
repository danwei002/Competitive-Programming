#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int a;
        cin >> a;
        if (a == 0) {
            return 0;
        }
        
        if (a == 1) {
            cout << "Minimum perimeter is 4 with dimensions 1 x 1" << endl;
            continue;
        }
        
        int sq = sqrt(a) + 1;
        while (a % sq != 0) {
            sq--;
        }
        
        int l = sq;
        int w = a / l;
        int p = 2 * l + 2 * w;
        cout << "Minimum perimeter is " << p << " with dimensions " << l << " x " << w << endl;
    }
}