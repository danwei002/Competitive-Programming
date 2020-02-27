#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    int shops[N][M + 1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            shops[i][j] = 0;
        }
    }
    
    for (int i = 0; i < K; i++) {
        int x, y, R, B;
        cin >> x >> y >> R >> B;
        x -= 1;
        y -= 1;
        int mx = max(0, x- R);
        int mn = min(N - 1, x + R);
        
        for (int j = mx; j <= mn; j++) {
            int rDiff = abs(j - x);
            int cDiff = abs(sqrt(pow(R, 2) - pow(rDiff, 2)));
            shops[j][max(0, y - cDiff)] += B;
            shops[j][min(M, y + cDiff + 1)] -= B;
        }
    }
    
    int max = 0;
    int ct = 0;
    for (int i = 0; i < N; i++) {
        int cur = 0;
        for (int j = 0; j < M; j++) {
            cur += shops[i][j];
            if (cur > max) {
                ct = 1;
                max = cur;
            } else {
                if (cur == max) {
                    ct++;
                }
            }
        }
    }
    cout << max << endl << ct;
}