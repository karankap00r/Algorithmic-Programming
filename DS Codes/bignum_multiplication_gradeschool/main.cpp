//Grade school multiplication algorithm for multiplication of two integers
#include<bits/stdc++.h>
using namespace std;
int main()
{
 string a,b;
 int sum[100]={0};
 long long int i,res,j,temp,k;
 cin>>a>>b;
 for(i=b.length()-1;i>=0;i--)
 {
  res=0;
  temp=0;
  for(j=a.length()-1,k=b.length()-i-1;j>=0;j--,k++)
  {
   res=(a[j]-'0')*(b[i]-'0')+temp;
   temp=res/10;
   sum[k]=sum[k]+(res%10);
   temp=temp+(sum[k]/10);
   sum[k]=sum[k]%10;
  }
  while(temp)
  {
   sum[k]=sum[k]+temp%10;
   temp=temp/10+sum[k]/10;
   sum[k]=sum[k]%10;
   k++;
  }
 }
 for(i=k-1;i>=0;i--)
 {
  cout<<sum[i];
 }
 return 0;
}
