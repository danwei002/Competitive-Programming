#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    char c[s.length()];
    vector<char> clubs, diamonds, hearts, spades;
    for (int i = 0; i < s.length(); i++) {
        c[i] = s.at(i);
    }
    
    int index = 1;
    while (s.at(index) != 'D') {
        clubs.push_back(s.at(index));
        index++;
    }
    
    index++;
    while (s.at(index) != 'H') {
        diamonds.push_back(s.at(index));
        index++;
    }
    
    index++;
    while (s.at(index) != 'S') {
        hearts.push_back(s.at(index));
        index++;
    }
    
    index++;
    while (index < s.length()) {
        spades.push_back(s.at(index));
        index++;
    }

    int cPt = 0;
    int dPt = 0;
    int hPt = 0; 
    int sPt = 0;
    if (clubs.size() == 0) {
        cPt = 3;
    } else if (clubs.size() == 1) {
        cPt = 2;
    } else if (clubs.size() == 2) {
        cPt = 1;
    }
    
    if (diamonds.size() == 0) {
        dPt = 3;
    } else if (diamonds.size() == 1) {
        dPt = 2;
    } else if (diamonds.size() == 2) {
        dPt = 1;
    }
    
    if (hearts.size() == 0) {
        hPt = 3;
    } else if (hearts.size() == 1) {
        hPt = 2;
    } else if (hearts.size() == 2) {
        hPt = 1;
    }
    
    if (spades.size() == 0) {
        sPt = 3;
    } else if (spades.size() == 1) {
        sPt = 2;
    } else if (spades.size() == 2) {
        sPt = 1;
    }
    
    for (auto p: clubs) {
        if (p == 'A') {
            cPt += 4;
        } else if (p == 'K') {
            cPt += 3;
        } else if (p == 'Q') {
            cPt += 2;
        } else if (p == 'J') {
            cPt += 1;
        }
    }
    
    for (auto p: diamonds) {
        if (p == 'A') {
            dPt += 4;
        } else if (p == 'K') {
            dPt += 3;
        } else if (p == 'Q') {
            dPt += 2;
        } else if (p == 'J') {
            dPt += 1;
        }
    }
    
    for (auto p: hearts) {
        if (p == 'A') {
            hPt += 4;
        } else if (p == 'K') {
            hPt += 3;
        } else if (p == 'Q') {
            hPt += 2;
        } else if (p == 'J') {
            hPt += 1;
        }
    }
    
    for (auto p: spades) {
        if (p == 'A') {
            sPt += 4;
        } else if (p == 'K') {
            sPt += 3;
        } else if (p == 'Q') {
            sPt += 2;
        } else if (p == 'J') {
            sPt += 1;
        }
    }
    
    cout << "Cards Dealt              Points" << endl;
    cout << "Clubs ";
    for (auto p: clubs) {
        cout << p << " ";
    }
    cout << "             " << cPt << endl;
    
    cout << "Diamonds ";
    for (auto p: diamonds) {
        cout << p << " ";
    }
    cout << "             " << dPt << endl;
    
    cout << "Hearts ";
    for (auto p: hearts) {
        cout << p << " ";
    }
    cout << "             " << hPt << endl;
    
    cout << "Spades ";
    for (auto p: spades) {
        cout << p << " ";
    }
    cout << "             " << sPt << endl;
    cout << "                       Total " << cPt + dPt + hPt + sPt << endl;
}