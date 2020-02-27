#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int s; 
        cin >> s;
        if (s < min) {
            min = s;
        }
        
        if (s > max) {
            max = s;
        }
    }
    
    cout << max - min << endl;
