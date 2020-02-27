#include <bits/stdc++.h>

using namespace std;

int blood[8], patients[8];
int solve(int p, int b) {
    int s = 0;
    if (blood[b] > patients[p]) {
        s = patients[p];
        blood[b] -= patients[p];
        patients[p] = 0;
    } else {
        s = blood[b];
        patients[p] -= blood[b];
        blood[b] = 0;
    }
    return s;
}

int main() {
    for (int i = 0; i < 8; i++) {scanf("%d", &blood[i]);}
    for (int i = 0; i < 8; i++) {scanf("%d", &patients[i]);}
    
    int ans = 0;
    ans += solve(0, 0); 
    ans += solve(1, 1) + solve(1, 0);
    ans += solve(2, 2) + solve(2, 0);
    ans += solve(4, 4) + solve(4, 0);
    ans += solve(3, 3) + solve(3, 1) + solve(3, 2) + solve(3, 0);
    ans += solve(5, 5) + solve(5, 1) + solve(5, 4) + solve(5, 0);
    ans += solve(6, 6) + solve(6, 0) + solve(6, 2) + solve(6, 4);
    ans += solve(7, 7) + solve(7, 0) + solve(7, 1) + solve(7, 2);
    ans += solve(7, 3) + solve(7, 4) + solve(7, 5) + solve(7, 6);
    printf("%d\n", ans);
    return 0;
}