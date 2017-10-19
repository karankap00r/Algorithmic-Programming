#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[100][3],l,m,i,j;
    char ch;
    cout<<"Enter the sparse matrix : \n";
    cin>>mat[0][0]>>mat[0][1]>>mat[0][2];
    l=1;
    while(ch!='n')
    {
        cin>>mat[l][0]>>mat[l][1]>>mat[l][2];
        l++;
        cout<<"Continue ? ('y' or 'n')";
        cin>>ch;
    }
    cout<<"Original Matrix : \n";
    m=1;
    for(i=0;i<mat[0][0];i++)
    {
        for(j=0;j<mat[0][1];j++)
        {
            if(i==mat[m][0]&&j==mat[m][1])
            {
                cout<<mat[m][2]<<" ";
                m++;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Transposed Sparse Matrix is :\n";
    for(i=0;i<l;i++)
    {
        swap(mat[i][0],mat[i][1]);
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<"\n";
    }
    return 0;
}
