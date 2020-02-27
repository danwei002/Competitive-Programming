#include <bits/stdc++.h>

using namespace std;

bool primeCheck(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
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
    int t = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        int old = x;
        int sum = 0;
        while (x > 0) {
            int m = x % 10;
            sum += m;
            x /= 10;
        }

        if (primeCheck(old) and primeCheck(sum)) {
            t++;
        }
    }
    cout << t << endl;
}