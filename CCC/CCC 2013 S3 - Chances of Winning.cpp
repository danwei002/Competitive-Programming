#include <bits/stdc++.h>

using namespace std;

int game[3][6] = {{0,0,0,0,0,0}, {0,0,0,1,1,2}, {1,2,3,2,3,3}};
int score[4];
int T, U;

int find(int t1, int t2) {
    for(int i = 0; i < 6; i++) {if (game[1][i] == t1 and game[2][i] == t2) {return i;}}
    return 0;
}

int nxt(){
    for(int i = 0; i < 6; i++) {if (game[0][i] == 0) {return i;}}
    return -1;
}

int play() {
    int r = 0;
    int n = nxt();
    if(n == -1) {
        r = 1;
        for(int j = 0; j < 4; j++) {if (T != j and score[j] >= score[T]) {r = 0;}}
    } else {
        game[0][n] = 1;
        int t1 = game[1][n];
        int t2 = game[2][n];
        
        score[t1] += 3;
        r += play();
        score[t1] -= 3;
        
        score[t2] += 3;
        r += play();
        score[t2] -= 3;
        
        score[t1]++; score[t2]++;
        r += play();
        score[t1]--; score[t2]--;
        game[0][n] = 0;
    }
    return r;
}

int main() {
    scanf("%d%d", &T, &U); T -= 1;
    for(int i = 0; i < U; i++){
        int A, B; scanf("%d%d", &A, &B); A -= 1; B -= 1;
        int C = find(A, B);
        game[0][C] = 1;
        int a, b; scanf("%d%d", &a, &b);
        if(a > b) {score[A] += 3;} 
        else if (a == b){score[A]++; score[B]++;}
        else if(a < b) {score[B] += 3;}
    }
    printf("%d\n", play());
}