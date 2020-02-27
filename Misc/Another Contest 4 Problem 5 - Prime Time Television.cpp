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
    
    long int sqrtN = (long int ) sqrt(n) + 1;
    
    for(long i = 6; i <= sqrtN; i += 6) {
        if(n % (i - 1) == 0 || n % (i + 1) == 0) {
            return false;
        }
    }
    return true;
}