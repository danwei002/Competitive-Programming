#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int m[N];
    
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    
    int n = sizeof(m)/sizeof(m[0]);
    sort(m, m+n);
    
    if (N % 2 == 0) {
        for (int i = 0; i < N/2; i++) {
            cout << m[N/2 - 1 - i] << " " << m[N/2 + i] << " ";
        }
    } else {
        int lows[N/2 + 1];
        int highs[N/2];
        
        for (int i = N/2; i >= 0; i--) {
            lows[i] = m[N/2 - i];
        }
        
        for (int j = 0; j < N/2; j++) {
            highs[j] = m[N/2 + j + 1];
        }
        
        cout << lows[0] << " ";
        
        for (int k = 0; k < N/2; k++) {
            cout << highs[k] << " " << lows[1 + k] << " ";
        }
    }
}