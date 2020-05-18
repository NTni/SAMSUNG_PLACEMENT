#include<iostream>
using namespace std;
void fun(int* arr,int n)
{
    int l = 0;
    int r = n-1;
    while(l<=r)
    {
        if(arr[l]==0 && arr[r]==1)
        {
            l++;
            r--;
        }
        else if(arr[l]==1 && arr[r]==0)
        {
            int a = arr[l];
            arr[l] = arr[r];
            arr[r] = a;
            r--;
            l++;
        }
        else if(arr[l]==0 && arr[r]==0)
        {
            l++;
        }
        else if(arr[l]==1 && arr[r]==1)
        {
            r--;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
}
int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    fun(arr,n);
    return 0;
}
