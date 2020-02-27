#include <bits/stdc++.h>

using namespace std;
const int maxn = 501;
bool network[maxn][maxn];
void close(int N) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (network[y][x]) {
                for (int z = 0; z < N; z++) {
                    if (network[x][z]) {
                        network[y][z] = true;
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            network[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s.at(j) == '1') {
                network[i][j] = true;
            }
        }
    }
    
    close(N);
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cnt += !(network[i][j] || network[j][i]);
        }
    }
    cout << cnt << endl;
}