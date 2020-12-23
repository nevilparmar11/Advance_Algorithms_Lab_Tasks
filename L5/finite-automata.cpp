/*
* @Author: nevil
* @Date:   2020-08-07 15:51:28
* @Last Modified by:   nevil
* @Last Modified time: 2020-08-19 02:25:36
*/

/*
finite automata based string matching algorithm.
It create the table and checks for the matching string in the text on its own.
*/

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int getNextState(string pat, int M, int state, int x)
{
	if (state < M && x == pat[state])
		return state + 1;

	int ns, i;

	for (ns = state; ns > 0; ns--)
	{
		if (pat[ns - 1] == x)
		{
			for (i = 0; i < ns - 1; i++)
				if (pat[i] != pat[state - ns + 1 + i])
					break;
			if (i == ns - 1)
				return ns;
		}
	}

	return 0;
}

void computeTF(string pat, int M, int TF[][NO_OF_CHARS])
{
	int state, x;
	for (state = 0; state <= M; ++state)
		for (x = 0; x < NO_OF_CHARS; ++x)
			TF[state][x] = getNextState(pat, M, state, x);
}

void search(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();

	int TF[M + 1][NO_OF_CHARS];

	computeTF(pat, M, TF);
	bool found = false;
	int i, state = 0;
	for (i = 0; i < N; i++)
	{
		state = TF[state][txt[i]];
		if (state == M)
		{
			found = true;
			cout << " Pattern found at index " << i - M + 1 << endl;
		}
	}

	if(!found)
		cout << "Pattern Not Found" << endl;
}

int main()
{
	string txt, pat;
	cout << "Enter Text : ";
	cin >> txt;

	cout << "Enter your pattern to be searched :";
	cin >> pat;

	search(pat, txt);
	return 0;
}
