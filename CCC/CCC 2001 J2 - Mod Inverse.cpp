#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, m;
    scanf("%d", &x); scanf("%d", &m);
    for (long long n = 1; n < m; n++) {
        int s = m * n + 1;
        if (s % x == 0) {
            cout << s/x << endl;
            return 0;
        }
    }
    cout << "No such integer exists." << endl;
}