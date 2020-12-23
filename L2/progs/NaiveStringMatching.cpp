/*
* @Author: nevil
* @Date:   2020-07-17 15:35:27
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-26 14:59:50
*/
#include <bits/stdc++.h>
using namespace std;

void naiveMatch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();
	bool found = 0;

	for (int i = 0; i <= N - M; i++) {
		int j;

		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) {	
			cout << "Pattern found at index "
			     << i << endl;
			found = 1;     
		}
	}

	if(!found)
		cout << "Pattern not found" << endl;
}

int main()
{
	string text, pattern;
	cout << "Enter Your TEXT : ";
	cin >> text;
	cout << "Enter pattern to search : ";
	cin >> pattern;

	naiveMatch(pattern, text);
	return 0;
}

