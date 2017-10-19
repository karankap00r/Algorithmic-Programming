int search(int x,int s,int e)
{
    while(s<=e)
    {
        int mid = (s+e)>>1;
        if (query(mid)>=x)
            e=mid-1;
        else
            s=mid+1;
    }
    return s;
}
