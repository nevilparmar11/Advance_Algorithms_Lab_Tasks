/*
* @Author: nevil
* @Date:   2020-09-07 12:31:12
* @Last Modified by:   nevil
* @Last Modified time: 2020-09-07 21:18:51
*/

#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
	int x;
	int y; 
}; 

float dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 

float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n - 1; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

int main() 
{ 
	int n;
	cout << "Enter the total number of points : ";
	cin >> n; // number of points
	struct Point points[n];
	cout << "Enter " << n << " points in the (x , y) format" << endl;
	int i;
	for(i = 0 ; i < n; i++)
	{
		cin >> points[i].x ;
		cin >> points[i].y;
	}
	cout << "The smallest distance is " << bruteForce(points, n); 
	return 0; 
} 
