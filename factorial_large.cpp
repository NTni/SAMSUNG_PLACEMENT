#include <bits/stdc++.h>
#include <iostream>
#define MAX 1000
using namespace std;
int product(int n,int* arr,int size)
{
    int carry = 0;
    int pro;
    for(int i=0;i<size;i++)
    {
        pro = (arr[i]*n) + carry;
        arr[i] = pro%10;
        carry = pro/10;
    }
    while(carry)
    {
        arr[size] = carry%10;
        carry = carry/10;
        size++;
    }
    return size;
}
void fun(int n)
{
    int arr[MAX];
    int size = 1;
    arr[0] = 1;
    for(int i=2;i<=n;i++)
        size = product(i,arr,size);
    for(int i=size-1;i>=0;i--)
        cout<<arr[i];
}
int main()
{
	int n;
    cin>>n;
    fun(n);
	return 0;
}
