/*
* @Author: nevil
* @Date:   2020-07-17 16:05:53
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-26 15:01:56
*/
#include<bits/stdc++.h>
using namespace std;


int horspoolStringMatching(const string &P, const string &T) {

	// P = input text
	// T = pattern to be searched in the text

	// shift table for algo
	int table[126];

	int k = 0, flag = 0;

	int m = T.length();
	int n = P.length();
	int i, j;


	for (i = 0; i < 126; i++)
		table[i] = m;
	for (j = 0; j < m - 1; j++)
		table[T[j]] = m - 1 - j;

	i = m - 1;

	while (i <= n - 1) {

		k = 0;
		while (k <= m - 1 && T[m - 1 - k] == P[i - k]) {
			k++;
		}

		if (k == m) {
			return i - m + 1;
			flag = 1;
			break;
		}

		else {
			i = i + table[P[i]];
		}

	}

	// returns -1 if the pattern is not found in the given input string
	if (!flag)
		return -1;

}

int main()
{
	string text, pattern;
	cout << "Enter Your TEXT : ";
	cin >> text;
	cout << "Enter pattern to search : ";
	cin >> pattern;

	int index = horspoolStringMatching(text, pattern);
	if(index != -1)
		cout << "Pattern found at : " << index << endl ;
	else
		cout << "Patter not found !" << endl;
	return 0;
}
