#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001];
bool vis[1001][1001];
int M, N;

void solve(int m, int n) {
    if ((m == M and n == N) or (m == N and n == M)) {printf("%s\n", "yes"); exit(0);}
    if (m > M or n > N) {return;}
    if (vis[m][n]) {return;}
    vis[m][n] = 1;
    int val = grid[m][n];
    for (int i = 1; i <= sqrt(val); i++) {if (val % i == 0) {solve(i, val  / i); solve(val / i, i);}}
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            vis[i][j] = 0;
            scanf("%d", &grid[i][j]);
        }
    }
    solve(1, 1);
    printf("%s\n", "no");
}