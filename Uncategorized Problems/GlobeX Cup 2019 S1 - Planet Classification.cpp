#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N; long long K;
    cin >> N >> K;
    map<long long, long long> types;
    long long num = 0;

    for (long long i = 0; i < N; i++) {
        long long a;
        cin >> a;
        if (types.count(a) > 0) {
            cout << types[a] << endl;
            types[a]++;
        } else {
            cout << 0 << endl;
            types.insert({a, 1});
            num++;
        }
    }
    cout << num << endl; 
}