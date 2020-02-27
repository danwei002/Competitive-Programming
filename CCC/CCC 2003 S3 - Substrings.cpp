#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    unordered_set<string> substrings;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int total = 2;
        for (int k = 1; k < s.length(); k++) {
            for (int j = 0; j <= s.length() - k; j++) {
                string str = s.substr(j, k);
                substrings.insert(str);
            }
            total += substrings.size();
            substrings.clear();
        }
        cout << total << '\n';
    }
}