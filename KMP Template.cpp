#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=1000000;
char text[MAX],pat[MAX];
bool ans;
//0 based indexing
//Outputs all occurrences of 'pattern' in given 'text'
void computeLPSArray(char *pat, ll M, ll *lps);
void KMPSearch(char *pat, char *txt)
{
    ll M = strlen(pat);
    ll N = strlen(txt);
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    ll *lps = (ll *)malloc(sizeof(ll)*M);
    ll j  = 0;  // index for pat[]
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
    ll i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
      if (j == M)
      {
          ans=true;
        printf("Found pattern at index %lld \n", i-j);
        j = lps[j-1];
      }
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
void computeLPSArray(char *pat, ll M, ll *lps)
{
    ll len = 0;  // length of the previous longest prefix suffix
    ll i;
    lps[0] = 0; // lps[0] is always 0
    i = 1;
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example
           // AAACAAAA and i = 7.
           len = lps[len-1];
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ans=false; //initialize
        cin>>text>>pat;
        KMPSearch(pat, text);
        if(!ans)
            cout<<"Pattern not found!\n";
    }
    return 0;
}
