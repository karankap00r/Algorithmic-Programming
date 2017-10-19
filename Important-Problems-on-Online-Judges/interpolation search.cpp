#include<bits/stdc++.h>
using namespace std;
template <typename T>
int isearch(T arr[], int size, T key)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (arr[high] != arr[low] && key >= arr[low] && key <= arr[high]) {
        mid = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[mid] < key)
            low = mid + 1;
        else if (key < arr[mid])
            high = mid - 1;
        else
            return mid;
    }

    if (key == arr[low])
        return low ;
    else
        return -1;
}
int main()
{
    int n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<isearch(a,n,3);
    return 0;
}