/*
* @Author: nevil
* @Date:   2020-07-24 15:35:52
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-24 15:42:07
*/
#include<bits/stdc++.h>
using namespace std;

// To find gcd( a, b)
int gcd (int a, int b)
{
	if( a < b )
		return gcd(b,a);
	else if(a % b == 0)
		return b;
	else
		return gcd( b, a % b);
}

int main() {

  cout << gcd(16 , 26);

  return 0;
}