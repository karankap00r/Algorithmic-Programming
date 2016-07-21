#include<bits/stdc++.h>
using namespace std;
int comp(const void* a,const void* b)
{
    const char **ia=(const char**)a;
    const char **ib=(const char**)b;
    int len=strlen(*ia)+strlen(*ib)+1;
    
    char XY[len];
    strcpy(XY,*ia);
    strcat(XY,*ib);
    
    char YX[len];
    strcpy(YX,*ib);
    strcat(YX,*ia);
    
    return strcmp(YX,XY);
}
string convert(int x)
{
    string temp;
    if(x==0)
    {
        temp="0";
        return temp;
    }
    while(x)
    {
        temp=(char)(x%10+'0')+temp;
        x/=10;
    }
    return temp;
}
int main()
{
    int n,i,a[100];
    //string s[100];
    char *s[100]={"20","2","10","9"};
//    cin>>n;
//    for(i=0;i<n;i++)
//    {
//        cin>>a[i];
//        //s[i]=convert(a[i]);
//        itoa(a[i],s[i],10);
//    }
    n=4;
    qsort(s,n,sizeof(s[0]),comp);
    for(i=0;i<n;i++)
    {
        cout<<s[i];
    }
    return 0;
}