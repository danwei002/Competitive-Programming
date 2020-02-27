#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int c = 0;
    int f = 0;
    for (int i = 0; i < N; i++) {
        string d;
        cin >> d;
        int dotIndex = 0;
        while (d.at(dotIndex) != '.') {
            dotIndex++;
        }
        
        if (d.at(dotIndex + 1) == '5' or d.at(dotIndex + 1) == '6' or d.at(dotIndex + 1) == '7' or d.at(dotIndex + 1) == '8' or d.at(dotIndex + 1) == '9') {
            c++;
        } else {
            f++;
        }
    }
    cout << c << endl << f << endl;
    return 0;
}