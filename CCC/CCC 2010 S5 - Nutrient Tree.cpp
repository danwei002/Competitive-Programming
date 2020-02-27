#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string fTrim(string s) {
    int i = 0; 
    while (s.at(i) == ' ') {i++;} 
    return s.substr(i, s.length() - i);
}

int indexOf(string s, char find) {
    int i = 0;
    while (s.at(i) != find) {i++;}
    return i;
}

struct Node {
	int value;
	Node *left;
	Node *right;
	int nutrients[2501];
};

Node* buildTree(string s) {
    s = fTrim(s);
    if (s.at(0) >= '0' and s.at(0) <= '9') {
        Node *leaf = new Node();
        leaf -> left = NULL; leaf -> right = NULL;
        int index = 0;
        while (index < s.length() and s.at(index) >= '0' and s.at(index) <= '9') {
            index++;
        }
        string s2 = s.substr(0, 1 + index);
        int v = stoi(s2);
        leaf -> value = v;
        return leaf;
    } else {
        s = s.substr(1, s.length() - 2);
        s = fTrim(s);
        int i = 0;
        if (s.at(0) == '(') {
            int cnt = 1;
            i = 1;
            while (cnt > 0) {
                if (s.at(i) == '(') {cnt++;}
                else if (s.at(i) == ')') {cnt--;}
                i++;
            }
        } else {
            i = indexOf(s, ' ');
        }
        Node *node = new Node();
        node -> left = buildTree(s.substr(0, i + 1));
        node -> right = buildTree(s.substr(i + 1));
        return node;
    }
}

void maximize(Node *node, int X) {
    if (node -> left == NULL) {
        for (int i = 0; i <= X; i++) {
            node -> nutrients[i] = node -> value + i;
        }
    } else {
        int mxL, mxR, tpL, tpR;
        maximize(node -> left, X);
        maximize(node -> right, X);
        int oL[X + 1];
        int oR[X + 1];
        for (int i = 0; i <= X; i++) {
            mxL = 0; mxR = 0;
            for (int j = 0; j <= i; j++) {
                tpL = min((1 + j) * (1 + j), node -> left -> nutrients[i - j]);
                mxL = max(mxL, tpL);
                tpR = min((1 + j) * (1 + j), node -> right -> nutrients[i - j]);
                mxR = max(mxR, tpR);
            }
            oL[i] = mxL;
            oR[i] = mxR;
        }
        
        int mx, tp;
        for (int i = 0; i <= X; i++) {
            mx = 0;
            for (int j = 0; j <= i; j++) {
                tp = oL[j] + oR[i - j];
                mx = max(mx, tp);
            }
            node -> nutrients[i] = mx;
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	string s;
	getline(cin, s);
	int X;
	cin >> X;
	Node *tree = buildTree(s);
	maximize(tree, X);
	cout << tree -> nutrients[X] << "\n";
}