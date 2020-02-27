#include <bits/stdc++.h>

using namespace std;

bool inRange(double x, double y, double z) {
	return (x >= y && x <= z) || (x <= y && x >= z);
}

bool inter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double m1, m2, b1, b2, x, y;
	
	if (x1 == x2) {m1 = DBL_MAX; b1 = 0;} 
	else {m1 = (y1 - y2) / (x1 - x2);b1 = -m1 * x2 + y2;}
	
	if (x3 == x4) {m2 = DBL_MAX;b2 = 0;} 
	else {m2 = (y3 - y4) / (x3 - x4); b2 = -m2 * x4 + y4;}

	if (m1 == m2) {
	    if (m1 != DBL_MAX && m2 != DBL_MAX) {return b1 == b2 and (inRange(x3, x1, x2) or inRange(x4, x1, x2));} 
	    else {return x1 == x3 and (inRange(y3, y1, y2) or inRange(y4, y1, y2));}
	} else {
	    if (m1 != DBL_MAX and m2 != DBL_MAX) {
    		x = (b2 - b1) / (m1 - m2);
    		y = m1 * x + b1;
    		return inRange(x, x1, x2) and inRange(y, y1, y2) and inRange(x, x3, x4) and inRange(y, y3, y4);
	    } else {
    		if (m1 == DBL_MAX) {x = x1; y = m2 * x + b2;} 
    		else {x = x3; y = m1 * x + b1;}
    		return inRange(x, x1, x2) and inRange(y, y1, y2) and inRange(x, x3, x4) and inRange(y, y3, y4);
	    }
	}
}

int main () {
	double xr, yr, xj, yj; int n; scanf("%lf%lf%lf%lf%d", &xr, &yr, &xj, &yj, &n);
	bool b; int count = 0;
	for (int i = 0 ; i < n ; i++) {
	    b = false;
	    int corners; scanf("%d", &corners);
	    double x[corners]; double y[corners];
        for (int j = 0; j < corners; j++) {scanf("%lf%lf", &x[j], &y[j]);}
	    for (int j = 0 ; j < corners ; j++){
            if (j != corners - 1) {b = inter(xr, yr, xj, yj, x[j], y[j], x[j + 1], y[j + 1]);} 
            else {b = inter(xr, yr, xj, yj, x[j], y[j], x[0], y[0]);}
            if (b) {count++; break;}
	    }
	}
	printf("%d\n", count);
}