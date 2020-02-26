#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    scanf("%d", &m); scanf("%d", &n);
    int cnt = 0;
    for (int i = m; i <= n; i++) {
        string s = to_string(i);
        if (s == "1" or s == "8" or s == "0") {
            cnt++;
            continue;
        }
        
        bool b = true;
        for (int j = 0; j < s.length(); j++) {
            if (s.at(j) == '2' or s.at(j) == '3' or s.at(j) == '4' or s.at(j) == '5' or s.at(j) == '7') {
                b = false;
                break;
            }
            
            if (s.at(j) == '6') {
                if (s.at(s.length() - 1 - j) != '9') {
                    b = false;
                    break;
                }
            } else if (s.at(j) == '9') {
                if (s.at(s.length() - 1 - j) != '6') {
                    b = false;
                    break;
                }
            } else {
                if (s.at(j) != s.at(s.length() - 1 - j)) {
                    b = false;
                    break;
                }   
            }            
        }
        
        if (b) {
            cnt++;
        }
    }
    cout << cnt;
}