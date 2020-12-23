/*
* @Author: nevil
* @Date:   2020-08-14 16:10:50
* @Last Modified by:   nevil
* @Last Modified time: 2020-09-07 12:34:01
*/
#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
	int x; 
	int y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; // colinear 

	return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; // Doesn't fall in any of the above cases 
} 

int main() 
{ 
	struct Point p1, q1, p2, q2;

	cout << "Enter (x, y) points of P1 : " ;
	cin >> p1.x >> p1.y;

	cout << "Enter (x, y) points of Q1 : " ;
	cin >> q1.x >> q1.y;

	cout << "Enter (x, y) points of P2 : " ;
	cin >> p2.x >> p2.y;

	cout << "Enter (x, y) points of Q2 : " ;
	cin >> q2.x >> q2.y;

	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 

	return 0; 
} 
