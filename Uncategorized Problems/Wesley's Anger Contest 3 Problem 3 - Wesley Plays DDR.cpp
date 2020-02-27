#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int M;
    cin >> s >> M;
    
    if (s.length() == 1) {cout << 1 << "\n"; return 0;}
    if (M == 1) {
        string combo; int pts; cin >> combo >> pts;
        int ans = (int) s.length();
        while (s.length() >= combo.length()) {
            int index = s.find(combo);
            if (index < 0) {break;}
            else {
                ans += pts;
                s = s.substr(index + combo.length(), s.length() - combo.length());
            }
        }
        cout << ans << "\n";
    } else {
        pair<string, int> combos[M];
        for (int i = 0; i < M; i++) {
            string c; int p;
            cin >> c >> p;
            combos[i] = {c, p};
        }
        int ans = (int) s.length();
        int i = 0; 
        while (i < s.length()) {
            int selection = -1;
            for (int j = 0; j < M; j++) {
                int len = combos[j].first.length();
                if (i + len > s.length()) {continue;}
                if (s.substr(i, len) == combos[j].first) {
                    if (selection == -1) {selection = j;}
                    else {
                        if (len >= combos[selection].first.length()) {selection = j;}
                    }
                }
            }
            
            if (selection != -1) {
                ans += combos[selection].second;
                i += combos[selection].first.length();
            } else {
                i++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}