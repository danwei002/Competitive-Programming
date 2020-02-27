#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int f;
    scanf("%d", &N);
    
    int L[2001];
    int sums[4001] = {};
    for (int i = 0; i < N; i++) {
        scanf("%d", &f);
        L[f]++;
    }
    
    for (int a = 0; a <= 2000; a++) {
        if (L[a]) {
            if (L[a] > 1) {
                sums[a * 2] += L[a] / 2;
            }
            
            for (int b = a + 1; b <= 2000; b++) {
                sums[a + b] += min(L[a], L[b]);
            }
        }
    }
    
    int currentMax = 1;
    int occurences = 0;
    for (int j = 0; j < 4001; j++) {
        if (sums[j] > currentMax) {
            currentMax = sums[j];
            occurences = 1;
        } else if (sums[j] == currentMax) {
            occurences++;
        }
    }
    
    cout << currentMax << " " << occurences;
}