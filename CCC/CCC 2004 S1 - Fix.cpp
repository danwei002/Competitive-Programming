#include <bits/stdc++.h>

using namespace std;

bool hasSuffix(string s1, string s2) {
    string subst = "";
    if (s1.length() < s2.length()) {
        subst = s2.substr(s2.length() - s1.length(), s1.length());
        if (subst == s1) {
            return true;
        }
    } else if (s1.length() > s2.length()) {
        subst = s1.substr(s1.length() - s2.length(), s2.length());
        if (subst == s2) {
            return true;
        }
    } else {
        return s1 == s2;
    }
    return false;
}

bool hasPrefix(string s1, string s2) {
    string subst = "";
    if (s1.length() < s2.length()) {
        subst = s2.substr(0, s1.length());
        if (subst == s1) {
            return true;
        }
    } else if (s1.length() > s2.length()) {
        subst = s1.substr(0, s2.length());
        if (subst == s2) {
            return true;
        }
    } else {
        return s1 == s2;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (hasSuffix(s1, s2) or hasSuffix(s2, s3) or hasSuffix(s1, s3) or hasPrefix(s1, s2) or hasPrefix(s2, s3) or hasPrefix(s1, s3)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;   
}