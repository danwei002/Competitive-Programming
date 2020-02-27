#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, g, r, o, m;
    cin >> p >> g >> r >> o >> m;
    
    int min = INT_MAX;
    int ct = 0;
    for (int a = 0; a <= m / p + 1; a++) {
        for (int b = 0; b <= m / g + 1; b++) {
            for (int c = 0; c <= m / r + 1; c++) {
                for (int d = 0; d <= m / o + 1; d++) {
                    if (a * p + b * g + c * r + d * o == m) {
                        cout << "# of PINK is " << a << " ";
                        cout << "# of GREEN is " << b << " ";
                        cout << "# of RED is " << c << " ";
                        cout << "# of ORANGE is " << d << " ";
                        if (a + b + c + d < min) {
                            min = a + b + c + d;
                        }
                        ct++;
                        cout << endl;
                    }
                }
            }
        }
    }
    cout << "Total combinations is " << ct << "." << endl;
    cout << "Minimum number of tickets to print is " << min << "." << endl;
}