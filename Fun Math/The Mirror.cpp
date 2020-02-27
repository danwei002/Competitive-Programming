#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if(n == 2 || n == 3) {
        return true;
    }
    
    if(n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    long long sqrtN = sqrt(n) + 1;
    
    for(long long i = 6; i <= sqrtN; i += 6) {
        if(n % (i - 1) == 0 || n % (i + 1) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int j = a; j < b; j++) {
            if (isPrime(j)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}