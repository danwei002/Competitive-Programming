#include <bits/stdc++.h>

using namespace std;

string toBinary(long long f) {
    int pw = 0;
    for (int i = 0; i <= 30; i++) {
        if (f >= pow(2, pw)) {
            pw = i;
        }
    }
    
    string res = "";
    while (pw >= 0) {
        if (f - pow(2, pw) >= 0) {
            res += "1";
            f -= pow(2, pw);
            pw--;
        } else {
            res += "0";
            pw--;
        }
    }
    return res.substr(1, res.length() - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long f;
        scanf("%lld", &f);
        if (f == 0) {cout << "0000" << endl; continue;}
        
        string s = toBinary(f);
        int md = s.length() % 4;
        for (int i = 0; i < 4 - md; i++) {
            s = "0" + s;
        }
        for (int i = 0; i < s.length(); i+=4) {
            if (i == 0) {
                if (s.substr(i, 4) != "0000") {
                    cout << s.substr(i, 4) << " ";
                }
            } else {
                cout << s.substr(i, 4) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}