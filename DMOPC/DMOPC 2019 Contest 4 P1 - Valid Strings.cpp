#include <bits/stdc++.h>

using namespace std;

bool valid(string s) {
    if (s == "") {return true;}
    if (s.at(0) == '(') {
        int count = 1; int index = 1;
        while (index != s.length() and count > 0 ) {
            if (s.at(index) == '(') {count++;} 
            else if (s.at(index) == ')') {count--;}
            index++;
        }
        
        if (index == s.length()) {
            if (s.at(index - 1) != ')') {return false;}
            else {return valid(s.substr(1, s.length() - 2));}
        } else {
            return valid(s.substr(0, index)) and valid(s.substr(index));
        }
    } else if (s.at(0) >= '0' and s.at(0) <= '9') {
        int index = 0; 
        while (index != s.length() and s.at(index) >= '0' and s.at(index) <= '9') {index++;}
        if (index == s.length()) {return true;}
        else {return valid(s.substr(index));}
    } else {
        return false;
    }
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (valid(s)) {cout << "YES\n";}
        else {cout << "NO\n";}
    }
    return 0;
}