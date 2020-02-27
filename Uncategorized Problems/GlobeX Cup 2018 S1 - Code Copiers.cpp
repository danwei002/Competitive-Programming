#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    set<int> s;
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        s.insert(a);
    }
    cout << N - s.size() + 1 << endl;
}