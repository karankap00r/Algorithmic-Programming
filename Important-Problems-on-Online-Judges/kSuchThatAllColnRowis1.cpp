#include<bits/stdc++.h>
using namespace std;
#define ll long long
int find(bool arr[n][n])
{
    // Start from top-most rightmost corner
    // (We could start from other corners also)
    int i=0, j=n-1;
 
    // Initialize result
    int res = -1;
 
    // Find the index (This loop runs at most 2n times, we either
    // increment row number or decrement column number)
    while (i<n && j>=0)
    {
        // If current element is 0, then this row may be a solution
        if (arr[i][j] == 0)
        {
            // Check for all elements in this row
            while (j >= 0 && (arr[i][j] == 0 || i == j))
                j--;
 
            // If all values are 0, then store this row as result
            if (j == -1)
            {
                res = i;
                break;
            }
 
            // We reach here if we found a 1 in current row, so this
            //  row cannot be a solution, increment row number
            else i++;
        }
        else // If current element is 1
        {
            // Check for all elements in this column
            while (i<n && (arr[i][j] == 1 || i == j))
                i++;
 
            // If all elements are 1
            if (i == n)
            {
                res = j;
                break;
            }
 
            // We reach here if we found a 0 in current column, so this
            // column cannot be a solution, increment column number
            else j--;
        }
    }
 
    // If we could not find result in above loop, then result doesn't exist
    if (res == -1)
       return res;
 
    // Check if above computed res is valid
    for (int i=0; i<n; i++)
       if (res != i && arr[i][res] != 1)
          return -1;
    for (int j=0; j<n; j++)
       if (res != j && arr[res][j] != 0)
          return -1;
 
    return res;
}
int main()
{
    ll r,c,i,j,a[100][100],temp;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    i=0;
    j=c-1;
    while(i<r&&j>=0)
    {
        j=c-1;
        if(a[i][j]==0)
        {
            while(j>=0&&a[i][j]==0)
            {
                j--;
            }
            j++;
        }
        if(j==-1)
        {
            bool flag=true;
            for(temp=0;temp<r;temp++)
            {
                if(temp==i)
                    continue;
                if(!a[temp][i])
                {
                    flag=false;
                    cout<<"Not Found";
                    return 0;
                }
            }
            if(flag)
            {
                cout<<i+1<<"\n";
                return 0;
            }
        }
        i++;
    }
    cout<<"Not Found";
    return 0;
}