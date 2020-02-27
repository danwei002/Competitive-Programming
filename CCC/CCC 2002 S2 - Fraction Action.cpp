#include <bits/stdc++.h>

using namespace std;

int gcf(int a, int b) {
    int max = 1;
    if (a > b) {
        for (int i = 2; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                max = i;
            }
        }
    } else {
        for (int i = 2; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                max = i;
            }
        }
    }
    return max;
}

int main() {
    int n, d;
    cin >> n >> d;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    int cnt = 0;
    
    while (n >= d) {
        n -= d;
        cnt++;
    }

    int g = gcf(n, d);
    n /= g;
    d /= g;
    
    if (cnt == 0) {
        cout << n << "/" << d;
    } else {
        if (n == 0) {
            cout << cnt;
        } else {
            cout << cnt << " " << n << "/" << d;
        }
    }
}