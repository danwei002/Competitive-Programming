#include <bits/stdc++.h>

using namespace std;

string sub(string s1, string s2) {
    string res = "";
    if (s1 == s2) {return "0";}
    if (s1.length() > s2.length()) {
        for (int i = 0; i < s1.length() - s2.length(); i++) {
            res += s1.at(i);
        }
        
        int a = s1.length() - s2.length();
        for (int i = 0; i < s2.length(); i++) {
            char c1 = s1.at(a + i); char c2 = s2.at(i);
            int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
            int diff;
            if (q1 < q2) {
                q1 += 10;
                diff = q1 - q2;
                char old = res.at(res.length() - 1);
                if (old == '0') {
                    int find = res.length() - 1;
                    while (res.at(find) == '0') {
                        res[find] = '9';
                        find--;
                    }
                    old = res.at(find);
                    int intOld = (int) old - 48;
                    intOld -= 1;
                    old = (char) intOld + 48;
                    res[find] = old;
                } else {
                    res = res.substr(0, res.length() - 1);
                    int intOld = (int) old - 48;
                    intOld -= 1;
                    old = (char) intOld + 48;
                    res += old;
                }
            } else {
                diff = q1 - q2;
            }

            res += (char) diff + 48;
        }
    } else if (s2.length() > s1.length()) {
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            res += s2.at(i);
        }
        
        int a = s2.length() - s1.length();
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s2.at(a + i); char c2 = s1.at(i);
            int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
            int diff;
            if (q1 < q2) {
                q1 += 10;
                diff = q1 - q2;
                char old = res.at(res.length() - 1);
                if (old == '0') {
                    int find = res.length() - 1;
                    while (res.at(find) == '0') {
                        res[find] = '9';
                        find--;
                    }
                    old = res.at(find);
                    int intOld = (int) old - 48;
                    intOld -= 1;
                    old = (char) intOld + 48;
                    res[find] = old;
                } else {
                    res = res.substr(0, res.length() - 1);
                    int intOld = (int) old - 48;
                    intOld -= 1;
                    old = (char) intOld + 48;
                    res += old;
                }
            } else {
                diff = q1 - q2;
            }

            res += (char) diff + 48;
        }
    } else {
        if (s1 == s2) {
            return "0";
        }
        
        if (s1.compare(s2) > 0) {
            for (int i = 0; i < s1.length(); i++) {
                char c1 = s1.at(i); char c2 = s2.at(i);
                int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
                int diff;
                if (q1 < q2) {
                    q1 += 10;
                    diff = q1 - q2;
                    char old = res.at(res.length() - 1);
                    if (old == '0') {
                        int find = res.length() - 1;
                        while (res.at(find) == '0') {
                            res[find] = '9';
                            find--;
                        }
                        old = res.at(find);
                        int intOld = (int) old - 48;
                        intOld -= 1;
                        old = (char) intOld + 48;
                        res[find] = old;
                    } else {
                        res = res.substr(0, res.length() - 1);
                        int intOld = (int) old - 48;
                        intOld -= 1;
                        old = (char) intOld + 48;
                        res += old; 
                    }
                } else {
                    diff = q1 - q2;
                }
                res += (char) diff + 48;
            }
        } else {
            for (int i = 0; i < s2.length(); i++) {
                char c1 = s2.at(i); char c2 = s1.at(i);
                int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
                int diff;
                if (q1 < q2) {
                    q1 += 10;
                    diff = q1 - q2;
                    char old = res.at(res.length() - 1);
                    if (old == '0') {
                        int find = res.length() - 1;
                        while (res.at(find) == '0') {
                            res[find] = '9';
                            find--;
                        }
                        old = res.at(find);
                        int intOld = (int) old - 48;
                        intOld -= 1;
                        old = (char) intOld + 48;
                        res[find] = old;
                    } else {
                        res = res.substr(0, res.length() - 1);
                        int intOld = (int) old - 48;
                        intOld -= 1;
                        old = (char) intOld + 48;
                        res += old;
                    }
                } else {
                    diff = q1 - q2;
                }
                res += (char) diff + 48;
            }
        }
    }
    
    int st = 0;
    while (res.at(st) == '0') {
        st++;
    }
    res = res.substr(st, res.length() - st);
    return res;
}

string add(string s1, string s2) {
    string res = "";
    bool dNeg = false;
    if ((s1.at(0) == '-' and s2.at(0) == '-') or (s1.at(0) != '-' and s2.at(0) != '-')) {
        if (s1.at(0) == '-' and s2.at(0) == '-') {s1 = s1.substr(1, s1.length() - 1); s2 = s2.substr(1, s2.length() - 1); dNeg = true;}
        if (s1.length() < s2.length()) {
            int a = s1.length() - 1;
            int b = s2.length() - 1;
            int carry = 0;
            for (int i = 0; i < s1.length(); i++) {
                char c1 = s1.at(a - i); char c2 = s2.at(b - i);
                int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
                int sum = q1 + q2 + carry;
                int append = sum % 10;
                carry = sum / 10;
                char put = (char) append + 48;
                res.insert(0, 1, put);
            }
            
            for (int i = s2.length() - s1.length() - 1; i >= 0; i--) {
                char c = s2.at(i);
                int q = (int) c - 48;
                int sum = q + carry;
                int append = sum % 10;
                carry = sum / 10;
                char put = (char) append + 48;
                res.insert(0, 1, put);
            }
            
            if (carry != 0) {
                char f = (char) carry + 48;
                res.insert(0, 1, f);
            }
        } else if (s2.length() < s1.length()) {
            int a = s1.length() - 1;
            int b = s2.length() - 1;
            int carry = 0;
            for (int i = 0; i < s2.length(); i++) {
                char c1 = s1.at(a - i); char c2 = s2.at(b - i);
                int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
                int sum = q1 + q2 + carry;
                int append = sum % 10;
                carry = sum / 10;
                char put = (char) append + 48;
                res.insert(0, 1, put);
            }
            
            for (int i = s1.length() - s2.length() - 1; i >= 0; i--) {
                char c = s1.at(i);
                int q = (int) c - 48;
                int sum = q + carry;
                int append = sum % 10;
                carry = sum / 10;
                char put = (char) append + 48;
                res.insert(0, 1, put);
            }
            
            if (carry != 0) {
                char f = (char) carry + 48;
                res.insert(0, 1, f);
            }
        } else {
            int a = s1.length() - 1;
            int b = s2.length() - 1;
            int carry = 0;
            for (int i = 0; i < s1.length(); i++) {
                char c1 = s1.at(a - i); char c2 = s2.at(b - i);
                int q1 = (int) c1 - 48; int q2 = (int) c2 - 48;
                int sum = q1 + q2 + carry;
                int append = sum % 10;
                carry = sum / 10;
                char put = (char) append + 48;
                res.insert(0, 1, put);
            }
            
            if (carry != 0) {
                char f = (char) carry + 48;
                res.insert(0, 1, f);
            }
        }
        if (dNeg) {
            res = '-' + res;
        }
    } else {
        if (s1.at(0) == '-' and s2.at(0) != '-') {
            s1 = s1.substr(1, s1.length() - 1);
            if (s1.length() > s2.length()) {
                res = sub(s2, s1);
                res.insert(0, 1, '-');
            } else if (s1.length() < s2.length()) {
                res = sub(s1, s2);
            } else {
                if (s1.compare(s2) > 0) {
                    res = sub(s1, s2);
                    res.insert(0, 1, '-');
                } else {
                    res = sub(s1, s2);
                }
            }
        } else if (s1.at(0) != '-' and s2.at(0) == '-') {
            s2 = s2.substr(1, s2.length() - 1);
            if (s2.length() > s1.length()) {
                res = sub(s1, s2);
                res.insert(0, 1, '-');
            } else if (s2.length() < s1.length()) {
                res = sub(s2, s1);
            } else {
                if (s2.compare(s1) > 0) {
                    res = sub(s2, s1);
                    res.insert(0, 1, '-');
                } else {
                    res = sub(s2, s1);
                }
            }
        }
    }
    

    return res;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << add(s1, s2) << endl;
    }
    return 0;
}