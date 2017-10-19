#include<bits/stdc++.h>
using namespace std;
#define d 256    // d is the number of characters in input alphabet
#define ll long long
bool ans;
void search(char pat[], char txt[], ll q)
{
	ll M = strlen(pat);
	ll N = strlen(txt);
	ll i, j;
	ll p = 0; // hash value for pattern
	ll t = 0; // hash value for txt
	ll h = 1;
    // The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M-1; i++)
		h = (h*d)%q;
	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++)
	{
		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters on by one
		if ( p == t )
		{
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
					break;
			}
			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			if (j == M)
            {
                printf("Pattern found at index %d \n", i);
                ans=true;
            }
		}
		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
			t = (t + q);
		}
	}
}
char txt[1000009],pat[1000009];
int main()
{
	ll q = 101; // A prime number
	cin>>txt>>pat;
	ans=false;
    search(pat, txt, q);
    if(!ans)
    {
        cout<<"Pattern not found in text";
    }
	return 0;
}
