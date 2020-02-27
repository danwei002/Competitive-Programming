#include <bits/stdc++.h>

using namespace std;

int romaDec(char roman) {
    if (roman == 'I') {return 1;}
    else if (roman == 'V') {return 5;}
    else if (roman == 'X') {return 10;}
    else if (roman == 'L') {return 50;}
    else if (roman == 'C') {return 100;}
    else if (roman == 'D') {return 500;}
    else if (roman == 'M') {return 1000;}
    return -1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    vector<char> roma; vector<char> ara;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) >= '0' and s.at(i) <= '9') {ara.push_back(s.at(i));}
        else {roma.push_back(s.at(i));}
    }
    
    vector<int> values;
    int dec = 0;
    for (int i = 0; i < roma.size(); i++) {
        int arabic = (int) ara[i] - 48; int roman = romaDec(roma[i]);
        int valuePair = arabic * roman;
        if (romaDec(roma[i + 1]) > roman and i != roma.size() - 1) {valuePair *= -1;}
        values.push_back(valuePair);
    }
    
    for (auto p: values) {dec += p;}
    cout << dec << "\n";
    return 0;
}