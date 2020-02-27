#include <bits/stdc++.h>

using namespace std;

bool hasPrefix(string code, string prefix) {
    if (code.substr(0, prefix.length()) == prefix) {
        return true;
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    char letter[k];
    string codes[k];
    for (int i = 0; i < k; i++) {
        char c;
        string s;
        cin >> c >> s;
        letter[i] = c; codes[i] = s;
    }
    
    string code;
    cin >> code;
    string res = "";
    while (code.length() > 0) {
        int i = 0;
        while (!hasPrefix(code, codes[i])) {
            i++;
        }
        
        res += letter[i];
        code = code.substr(codes[i].length(), code.length() - codes[i].length());
    }
    
    cout << res;
}