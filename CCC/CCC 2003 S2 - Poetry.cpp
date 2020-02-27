#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string v1, v2, v3, v4;
        getline(cin, v1); 
        getline(cin, v2); 
        getline(cin, v3); 
        getline(cin, v4);

        
        transform(v1.begin(), v1.end(), v1.begin(), ::tolower);
        transform(v2.begin(), v2.end(), v2.begin(), ::tolower);
        transform(v3.begin(), v3.end(), v3.begin(), ::tolower);
        transform(v4.begin(), v4.end(), v4.begin(), ::tolower);
        
        string s1, s2, s3, s4;
        for (int i = v1.length() - 1; i >= 0; i--) {
            s1 = v1;
            if (v1.at(i) == ' ') {
                s1 = v1.substr(i + 1, v1.length() - i - 1);
                for (int j = s1.length() - 1; j >= 0; j--) {
                    if (s1.at(j) == 'a' or s1.at(j) == 'e' or s1.at(j) == 'i' or s1.at(j) == 'o' or s1.at(j) == 'u') {
                        s1 = s1.substr(j, s1.length() - j);
                        break;
                    }
                }
                break;
            }
        }
        
        for (int i = v2.length() - 1; i >= 0; i--) {
            s2 = v2;
            if (v2.at(i) == ' ') {
                s2 = v2.substr(i + 1, v2.length() - i - 1);
                for (int j = s2.length() - 1; j >= 0; j--) {
                    if (s2.at(j) == 'a' or s2.at(j) == 'e' or s2.at(j) == 'i' or s2.at(j) == 'o' or s2.at(j) == 'u') {
                        s2 = s2.substr(j, s2.length() - j);
                        break;
                    }
                }
                break;
            }
        }
        
        for (int i = v3.length() - 1; i >= 0; i--) {
            s3 = v3;
            if (v3.at(i) == ' ') {
                s3 = v3.substr(i + 1, v3.length() - i - 1);
                for (int j = s3.length() - 1; j >= 0; j--) {
                    if (s3.at(j) == 'a' or s3.at(j) == 'e' or s3.at(j) == 'i' or s3.at(j) == 'o' or s3.at(j) == 'u') {
                        s3 = s3.substr(j, s3.length() - j);
                        break;
                    }
                }
                break;
            }
        }
        
        for (int i = v4.length() - 1; i >= 0; i--) {
            s4 = v4;
            if (v4.at(i) == ' ') {
                s4 = v4.substr(i + 1, v4.length() - i - 1);
                for (int j = s4.length() - 1; j >= 0; j--) {
                    if (s4.at(j) == 'a' or s4.at(j) == 'e' or s4.at(j) == 'i' or s4.at(j) == 'o' or s4.at(j) == 'u') {
                        s4 = s4.substr(j, s4.length() - j);
                        break;
                    }
                }
                break;
            }
        }
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
        transform(s4.begin(), s4.end(), s4.begin(), ::tolower);
        if (s1 == s2 and s2 == s3 and s3 == s4) {
            cout << "perfect" << endl;
        } else if (s1 == s2 and s3 == s4) {
            cout << "even" << endl;
        } else if (s1 == s3 and s2 == s4) {
            cout << "cross" << endl;
        } else if (s1 == s4 and s2 == s3) {
            cout << "shell" << endl;
        } else {
            cout << "free" << endl;
        }
    }
}