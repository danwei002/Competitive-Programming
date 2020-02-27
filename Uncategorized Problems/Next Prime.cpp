#include <bits/stdc++.h>

using namespace std;

bool f(int n) {
    if (n < 2) {
        return false;
    }
    if(n == 2 || n == 3) {
        return true;
    }
    
    if(n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    int sqrtN = sqrt(n) + 1;
    
    for(int i = 5; i <= sqrtN; i += 6) {
        if (n%i == 0 || n%(i+2) == 0)  {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        cout << 2;
    } else if (N == 2) {
        cout << 2;
    } else {
        int i = N;
        while (true) {
            if (f(i)) {
                cout << i;
                break;
            }
            i++;
        }
    }
}