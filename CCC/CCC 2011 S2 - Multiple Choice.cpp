#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int C = 0;
    scanf("%d", &N);
    
    char ans[N];
    char cAns[N];
    for (int i = 0; i < N; i++) {
        cin >> ans[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> cAns[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (ans[i] == cAns[i]) {C++;}
    }
    cout << C << endl;
    return 0;   
}