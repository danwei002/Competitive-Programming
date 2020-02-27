#include <bits/stdc++.h>

using namespace std;

int N, K;
int nums[300001];
double sums[300001];

int main() {
    scanf("%d%d", &N, &K);
    sums[0] = 0;
    for (int i = 1; i <= N; i++) {scanf("%d", &nums[i]); sums[i] = sums[i - 1] + nums[i];}

    double lo = 0; double hi = 1000000;
    
    while (hi - lo >= 0.000001) {
        bool b = false;
        double mid = (lo + hi) / 2;
        double avg = 0;
        for (int i = 1; i <= N; i++) {sums[i] = sums[i - 1] + nums[i] - mid;}
        for (int i = K; i <= N; i++) {
            if (sums[i] >= avg) {b = true; break;}
            avg = fmin(avg, sums[i - K + 1]);
        }
        
        if (b) {lo = mid;}
        else {hi = mid;}
    }
    printf("%.6f\n", lo);
    return 0;
}