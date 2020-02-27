#include <iostream>

using namespace std;

int main() {
    int N;
    int K;
    scanf("%d%d", &N, &K);
    int triangle[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }
    long long sum = 0;
    int cur, nxt;
    for (cur = 1, nxt = 2; nxt <= K; cur = nxt, nxt = 1.5 * cur) {
        int d = nxt - cur;
        for (int a = 0; a < N - nxt + 1; a++) {
            for (int b = 0; b <= a; b++) {
                int g = max(triangle[a + d][b], triangle[a + d][b + d]); 
                triangle[a][b] = max(triangle[a][b], g);
            }
        }
    }
    int d = K - cur;
    for (int i = 0; i < N - K + 1; i++) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = max(triangle[i][j], max(triangle[i + d][j] , triangle[i + d][j + d]));
            sum += triangle[i][j];
        }
    }
    printf("%lld\n", sum);
}